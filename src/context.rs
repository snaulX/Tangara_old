use crate::entry::TgEntry;
use std::fs::File;
use std::io::BufRead;
use std::{fs, io};

pub struct TgContext<'context> {
    pub(crate) entries: Vec<TgEntry<'context>>,
}

impl<'context> TgContext<'context> {
    pub fn create() -> TgContext<'context> {
        TgContext {
            entries: Vec::new(),
        }
    }

    // TODO: wrap result to Result<> to handle errors
    pub fn load_data(&mut self, file_name: &str) -> TgEntry {
        /*let file = File::open(file_name);
        let mut reader = io::BufReader::new(file);
        let mut entry_name = String::new();
        reader.read_line(&mut entry_name)?;*/
        //let loaded_entry = TgEntry::create(/*entry_name.as_str()*/file_name, Vec::new());

        /*if let lines = reader.lines() {
            // Consumes the iterator, returns an (Optional) String
            for line in lines {
                if let Ok(valid_line) = line {
                    for ch in valid_line.trim().chars() {
                        //pass
                    }
                }
            }
        }*/

        //self.entries.push(loaded_entry);
        //return loaded_entry;
        TgEntry::create(/*entry_name.as_str()*/ file_name, Vec::new())
    }
}
