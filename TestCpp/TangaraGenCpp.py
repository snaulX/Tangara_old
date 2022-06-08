import sys
import json

mainCode = []
funcsCode = []

def fixNamespaces(type):
    return '::'.join(type.split('.'))


def genParamsFuncCode(params):
    listParams = []
    for i in range(len(params)):
        param = params[i]
        type = fixNamespaces(param['type'].strip())
        name = 'arg_{}'.format(param['name'].strip())
        if type.endswith('*'):
            funcsCode.append('\t{} {} = static_cast<{}>(malloc(params[{}]->size));'.format(type, name, type, i))
            funcsCode.append('\tmemcpy({}, params[{}]->data, params[{}]->size);'.format(name, i, i))
        else:
            funcsCode.append('\t{} {} = *({}*)params[{}]->data;'.format(type, name, type, i))
        listParams.append(name)
    return ', '.join(listParams)


def genParamTypes(funcName, params):
    varName = '{}_paramTypes'.format(funcName)
    mainCode.append('TgParamTypes {};'.format(varName))
    length = len(params)
    mainCode.append('{}.length = {};'.format(varName, length))
    mainCode.append('{}.types = (uint32_t*)calloc({}, sizeof(uint32_t));'.format(varName, length))
    mainCode.append('{}.names = (char**)calloc({}, sizeof(char*));'.format(varName, length))
    for i in range(length):
        param = params[i]
        mainCode.append('{}.types[{}] = TgGetClassHash("{}");'.format(varName, i, param['type'].strip()))
        mainCode.append('{}.names[{}] = "{}";'.format(varName, i, param['name'].strip()))
    return varName

if len(sys.argv) == 2:
    reflectionFile = sys.argv[1]
else:
    reflectionFile = "tgrefldata.json"
with open(reflectionFile, "r") as file:
    reflData = json.load(file)
entries = reflData['entries']
for entry in entries:
    includes = entry['includes']
    includes.append('RuntimeCpp.hpp')
    for i in range(len(includes)):
        includes[i] = '#include "{}"'.format(includes[i])
    entryName = entry['name'].strip()
    eVarName = '{}_entry'.format(entryName)
    mainCode.append('Entry *{} = TgCreateEntry("{}");'.format(eVarName, entryName))
    classes = entry['classes']
    for cl in classes:
        className = cl['name'].strip()
        clNames = className.split('.')  # Work with namespaces
        clCppName = '::'.join(clNames)
        clCodeName = '_'.join(clNames)
        clVarName = '{}_class'.format(clCodeName)
        mainCode.append('auto *{} = new Class("{}");'.format(clVarName, className))
        ctors = cl['constructors']
        for i in range(len(ctors)):
            ctorName = 'tg_{}_ctor{}'.format(clCodeName, i)
            params = ctors[i]['params']
            funcsCode.append('extern "C" TgObj* {}(TgObj* params[])\n{{'.format(ctorName))
            funcsCode.append('\treturn TgPtr((void*) new {}({}), TgGetClassHash("{}"));\n}}'.format(
                clCppName, genParamsFuncCode(params), className)
            )
            mainCode.append('{}->CreateConstructor({}, {});'.format(
                clVarName, ctorName, genParamTypes('{}_ctor{}'.format(clCodeName, i), params))
            )
        methods = cl['methods']
        for method in methods:
            methodName = method['name'].strip()
            mVarName = 'tg_{}_{}'.format(clCodeName, methodName)
            params = method['params']
            funcsCode.append('extern "C" TgObj* {}(void* obj, TgObj* params[])\n{{'.format(mVarName))
            funcsCode.append('\tauto* cppObj = static_cast<{}*>(obj);'.format(clCppName))
            returnType = fixNamespaces(method['returnType'].strip())
            if returnType.startswith('const '):
                constModifier = 'const'
            else:
                constModifier = ''
            if returnType == 'void':
                funcsCode.append('\tcppObj->{}({});'.format(methodName, genParamsFuncCode(params)))
                funcsCode.append('\treturn TgNull();')
            elif not returnType.endswith('*'):
                funcsCode.append('\t{} result = cppObj->{}({});'.format(returnType, methodName, genParamsFuncCode(params)))
                funcsCode.append('\t{}* resultPtr = ({}*)malloc(sizeof({}));'.format(returnType, returnType, returnType))
                funcsCode.append('\t*resultPtr = result;')
                funcsCode.append('\tTgObj* tgObj = TgPtr((void* {})resultPtr, TgGetClassHash("{}"));'
                                 .format(constModifier, returnType))
                funcsCode.append('\treturn tgObj;')
            else:
                funcsCode.append('\tTgObj* tgObj = TgPtr((void* {})cppObj->{}({}), TgGetClassHash("{}"));'.format(
                    constModifier, methodName, genParamsFuncCode(params), returnType)
                )
                funcsCode.append('\treturn tgObj;')
            funcsCode.append('}')
            mainCode.append('{}->CreateMethod("{}", {}, TgGetClassHash("{}"), {});'.format(
                clVarName, methodName, mVarName, returnType, genParamTypes('{}_{}'.format(clCodeName, methodName), params)
            ))
        mainCode.append('{}->AddClass({});'.format(eVarName, clVarName))

    mainCode.append('return {};'.format(eVarName))
    with open('{}.Gen.cpp'.format(entryName), 'w') as file:
        file.write('// File was generated using TangaraGen.py\n')
        file.write('\n'.join(includes))
        file.write('\n\nusing namespace Tangara;\nusing namespace Tangara::Runtime::Cpp;\n')
        file.write('\n'.join(funcsCode))
        file.write('\n\nextern "C" TANGARA_API void* tgLoadEntry() \n{\n\t')
        file.write('\n\t'.join(mainCode))
        file.write('\n}')
        print('{}.Gen.cpp was generated'.format(entryName))
    mainCode.clear()
    funcsCode.clear()
