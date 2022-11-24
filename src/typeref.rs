use std::cell::RefCell;
use crate::context::TgContext;
use crate::r#type::TgType;

// TODO: shit, how to remove all these livetime annotations and make code nicer

pub trait TypeResolver<'cached> {
    fn resolve(&self, ctx: &'cached TgContext<'cached>) -> Option<&TgType<'cached>>;
}

pub struct TgTypeRef<'cached, T> {
    cached_type: RefCell<Option<&'cached TgType<'cached>>>,
    search_info: T
}

pub type TgTypeRefName<'cached> = TgTypeRef<'cached, String>;
pub type TgTypeRefId<'cached> = TgTypeRef<'cached, u64>;

impl<'cached> TgTypeRefName<'cached> {
    pub fn create(type_name: &str) -> TgTypeRefName<'cached> {
        TgTypeRef {
            cached_type: RefCell::new(None),
            search_info: type_name.to_string()
        }
    }
}

impl<'cached> TgTypeRefId<'cached> {
    pub fn create(type_id: u64) -> TgTypeRefId<'cached> {
        TgTypeRef {
            cached_type: RefCell::new(None),
            search_info: type_id
        }
    }
}

impl<'cached> TypeResolver<'cached> for TgTypeRefName<'cached> {
    fn resolve(&self, ctx: &'cached TgContext<'cached>) -> Option<&TgType<'cached>> {
        match &self.cached_type.take() {
            Some(cache) => Some(cache),
            None => {
                for entry in &ctx.entries {
                    for t in entry.get_types() {
                        if *t.get_name() == self.search_info {
                            let resolved_type = Some(t);
                            self.cached_type.replace(resolved_type);
                            return resolved_type
                        }
                    }
                }
                None
            }
        }
    }
}

impl<'cached> TypeResolver<'cached> for TgTypeRefId<'cached> {
    fn resolve(&self, ctx: &'cached TgContext<'cached>) -> Option<&TgType<'cached>> {
        match self.cached_type.take() {
            Some(cache) => Some(cache),
            None => {
                for entry in &ctx.entries {
                    for t in entry.get_types() {
                        if t.get_id() == self.search_info {
                            let resolved_type = Some(t);
                            self.cached_type.replace(resolved_type);
                            return resolved_type
                        }
                    }
                }
                None
            }
        }
    }
}