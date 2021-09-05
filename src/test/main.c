#include "Tangara.h"
#include "File.h"

int main(void)
{
    Class string = init_class(PUBLIC, DEFAULT, "string");
    Field name = init_field(PUBLIC, DEFAULT, "name", &string, "Alexander");
    VarBlock params = init_var_block();
    Func func = init_func(PUBLIC, DEFAULT, "func", NULL, &params);
    Class main = init_class(PUBLIC, DEFAULT, "Main");
    FieldBlock fb = init_field_block();
    main.fields = &fb;
    add_field(name, &fb /*main.fields*/);
    //add_func(func, main.methods);
    ClassBlock clb = init_class_block();
    add_class(main, &clb);
    printf("%s\n", clb.classes[0].name);
    FILE* file = open_write("test.tgr");
    write_class_block(file, &clb);
    close_file(file);
    file = open_read("test.tgr");
    read_class_block(file, &clb);
    printf("%s\n", clb.classes[0].fields->fields[0].var.name);
}