use crate::r#type::TgType;

pub struct TgEntry<'context> {
    name: String,
    types: Vec<TgType<'context>>,
}

impl<'context> TgEntry<'context> {
    pub(crate) fn create(name: &str, types: Vec<TgType<'context>>) -> TgEntry<'context> {
        TgEntry {
            name: name.to_string(),
            types,
        }
    }

    pub fn get_types(&self) -> &Vec<TgType<'context>> {
        &self.types
    }
}
