TgBuild.Include('Tangara.Cpp')
simdjson_target = TangaraCpp.Create({'simdjson.cpp', 'simdjson.h'})
return simdjson_target