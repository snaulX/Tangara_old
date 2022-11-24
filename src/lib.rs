pub mod context;
pub mod entry;
pub mod r#type;
pub mod typeref;

#[cfg(test)]
mod tests {
    use super::*;
    use crate::context::TgContext;
    use crate::r#type::TgType;

    #[test]
    fn systems_test() {
        // Create vector of types to save game systems
        let mut systems: Vec<&TgType> = Vec::new();
        // Create context for load entries
        let mut ctx = TgContext::create();
        // Load entry from sample game Tangara (reflection) data
        let entry = ctx.load_data("EnigmaLabs.tgdata");
        // Iterate every type in the loaded entry
        for _type in entry.get_types() {
            // Check if type is inherits from our base game system interface
            if _type.is_inherits("AlphaEngine.ISystem") {
                // Check type on singleton because all systems must be a singletons
                if _type.is_singleton() {
                    systems.push(_type);
                } else {
                    panic!("System must be singleton");
                }
            }
        }
        // Now in `systems` we have all systems collected from game reflection data
        //assert_eq!(systems[0].get_name().as_str(), "MySystem");
    }
}
