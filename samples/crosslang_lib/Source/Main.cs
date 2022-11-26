// https://github.com/simdjson/simdjson#quick-start
using System;
using System.IO;
using simdjson;

ondemand.parser _parser = new();
string contents = File.ReadAllText("twitter.json");
ondemand.document tweets = _parser.iterate(contents);
Console.WriteLine(tweets["search_metadata"]["count"]);