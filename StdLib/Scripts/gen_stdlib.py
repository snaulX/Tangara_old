import xxhash
import enum


class Token(enum.Enum):
    Literal = ''
    Struct = 'struct'
    Class = 'class'
    String = '"'
    Char = '\''
    LBrace = '('
    RBrace = ')'
    LBracket = '{'
    RBracket = '}'
    Public = 'public'
    Private = 'private'
    Protected = 'protected'
    Internal = 'internal'
    Final = 'final'
    Entry = 'entry'
    Link = 'link'
    NameSpace = 'namespace'
    Ctor = 'ctor'
    Semicolon = ';'
    Dot = '.'
    FloatNumb = ''
    IntNumb = ''
    LongNumb = ''
    DoubleNumb = ''


class TokenOutput:
    def __init__(self):
        self.tokens = []
        self.strings = []
        self.chars = []
        self.literals = []
        self.numbers = []

    def add_word(self, word):
        try:
            self.tokens.append(Token(word))
        except ValueError:
            self.tokens.append(Token.Literal)
            self.literals.append(word)

    def add_numb(self, numb, mod='i'):
        match mod.lower():
            case 'i':
                self.tokens.append(Token.IntNumb)
                self.numbers.append(numb)
            case 'f':
                self.tokens.append(Token.FloatNumb)
                self.numbers.append(numb)
            case 'l':
                self.tokens.append(Token.LongNumb)
                self.numbers.append(numb)
            case 'd':
                self.tokens.append(Token.DoubleNumb)
                self.numbers.append(numb)
            case _:
                raise ValueError("Number modifier {0} is not supported".format(mod))

    def add_str(self, string):
        self.tokens.append(Token.String)
        self.strings.append(string)

    def add_char(self, char):
        self.tokens.append(Token.Char)
        self.chars.append(char)


def tokenize(lines):
    result = TokenOutput()
    word = []
    is_string = False
    is_char = False
    is_word = False
    is_numb = False

    for line in lines:
        print(line)
        for ch in line:
            if is_numb:
                if ch.isdecimal() or ch == Token.Dot:
                    word.append(ch)
                    continue
                elif ch.isalpha():
                    strnumb = ''.join(word)
                    if Token.Dot.value in strnumb:
                        numb = float(strnumb)
                    else:
                        numb = int(strnumb)
                    result.add_numb(numb, ch)
                    is_numb = False
                    continue
                else:
                    strnumb = ''.join(word)
                    if Token.Dot.value in strnumb:
                        numb = float(strnumb)
                        result.add_numb(numb, 'd')
                    else:
                        numb = int(strnumb)
                        result.add_numb(numb)
                    is_numb = False

            if is_word:
                if ch.isalnum():
                    word.append(ch)
                    continue
                else:
                    ready_word = ''.join(word)
                    word.clear()
                    is_word = False
                    result.add_word(ready_word)
                    print(ready_word)

            if ch.isspace():
                continue
            elif ch.isalpha():
                is_word = True
                word.append(ch)
            elif ch.isnumeric():
                is_numb = True
                word.append(ch)
            else:
                token = Token(ch)
                if token == Token.Char:
                    is_char = True
                elif token == Token.String:
                    is_string = True
                result.tokens.append(token)

    return result


if __name__ == "__main__":
    with open("tangara_code.tgc") as file:
        tokens_output = tokenize(file.readlines())
    for token in tokens_output.tokens:
        print(token)
        if token == Token.Literal:
            print(tokens_output.literals.pop(0))
        elif token == Token.String:
            print(tokens_output.strings.pop(0))
