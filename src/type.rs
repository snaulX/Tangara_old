use crate::r#type::TgTypeKind::{AbstractClass, Class, FinalClass, Singleton, StaticClass};
use crate::typeref::TypeResolver;
use std::cell::RefCell;
use xxhash_rust::xxh3::xxh3_64_with_seed;

#[derive(PartialEq)]
pub enum TgTypeKind {
    Unknown,
    Class,
    Struct,
    FinalClass,
    StaticClass,
    Enum,
    Interface,
    AbstractClass,
    Record,
    TypeAlias,
    Singleton,
}

pub struct TgType<'context> {
    id: u64,
    name: String,
    kind: TgTypeKind,
    parents: RefCell<Vec<Box<dyn TypeResolver<'context>>>>,
}

impl<'context> TgType<'context> {
    pub(crate) fn create(name: &str, kind: TgTypeKind) -> TgType<'context> {
        const TYPE_HASH_SEED: u64 = 13347889;
        TgType {
            id: xxh3_64_with_seed(name.as_bytes(), TYPE_HASH_SEED),
            name: name.to_string(),
            kind,
            parents: RefCell::new(Vec::new()),
        }
    }

    pub fn get_name(&self) -> &String {
        &self.name
    }

    pub fn get_id(&self) -> u64 {
        self.id
    }

    pub fn inherit<TDef>(&self, parent: TDef)
    where
        TDef: TypeResolver<'context> + 'static,
    {
        self.parents.borrow_mut().push(Box::new(parent))
    }

    pub fn is_inherits(&self, type_name: &str) -> bool {
        false
    }

    pub fn is_singleton(&self) -> bool {
        self.kind == Singleton
    }

    pub fn is_class(&self) -> bool {
        self.kind == Class
            || self.kind == StaticClass
            || self.kind == FinalClass
            || self.kind == AbstractClass
    }
}
