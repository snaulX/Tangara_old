pub mod context;
pub mod entry;
pub mod r#type;
pub mod typeref;

#[cfg(test)]
mod tests {
    use crate::context::TgContext;
    use crate::r#type::TgType;
    use super::*;

    #[test]
    fn it_works() {
        let mut systems: Vec<&TgType> = Vec::new();
        let mut ctx = TgContext::create();
        let entry = ctx.load_data("EnigmaLabs.tgdata");
        let types = entry.get_types();
        for _type in types {
            if _type.is_inherits("AlphaEngine.ISystem") {
                if _type.is_singleton() {
                    systems.push(_type);
                } else {
                    panic!("System must be singleton");
                }
            }
        }
        assert_eq!(systems[0].get_name().as_str(), "MySystem");
    }
}
