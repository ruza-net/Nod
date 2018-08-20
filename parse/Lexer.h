//
// Created by Jan Růžička on 11/08/2018.
//

#ifndef NODPARSER_LEXER_H
#define NODPARSER_LEXER_H

#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

#include "Token.h"


namespace Nod
{
    enum class LexerState {
        BuildToken,
        Default,
        NewLine,

        Underscore,

        Integer,
        Float,

        String,
        StringEscape,

        Char,
        CharEscape,

        Identifier,

        Dollar,
        Operator,

        Dot,
        DoubleDot,

        Error,
        Eof,
    };

    enum class LexResult {
        Success,

        EarlyEof,
        BadEscape,

        OtherError,
    };

    class LexError {
        LexerState finalState;
        LexResult result;

        std::string message;

    public:
        LexError(LexerState s, LexResult r, std::string msg) : finalState(s), result(r), message(std::move(msg)) {}
    };


    using s = LexerState;
    using tt = TokenType;

    const std::map<std::string, TokenType> getKeywords() {
        static const std::map<std::string, TokenType> keywords = {
                {"as",        tt::As},
                {"attr",      tt::Attr},
                {"break",     tt::Break},
                {"case",      tt::Case},
                {"catch",     tt::Catch},
                {"class",     tt::Class},
                {"continue",  tt::Continue},
                {"del",       tt::Del},
                // tt::DelOpt
                {"do",        tt::Do},
                {"else",      tt::Else},
                {"enum",      tt::Enum},
                {"false",     tt::False},
                {"for",       tt::For},
                {"func",      tt::Func},
                {"gen",       tt::Gen},
                {"get",       tt::Get},
                // tt::GetOpt
                {"guard",     tt::Guard},
                {"if",        tt::If},
                {"in",        tt::In},
                // tt::InOpt
                {"infix",     tt::Infix},
                {"init",      tt::Init},
                // tt::InitAmp
                // tt::InitOpt
                {"inline",    tt::Inline},
                {"left",      tt::Left},
                {"let",       tt::Let},
                // tt::LetAmp
                // tt::LetOpt
                {"loop",      tt::Loop},
                {"match",     tt::Match},
                {"mut",       tt::Mut},
                {"namespace", tt::Namespace},
                {"postfix",   tt::Postfix},
                {"prefix",    tt::Prefix},
                {"protocol",  tt::Protocol},
                {"pub",       tt::Pub},
                // tt::PubOpt
                {"return",    tt::Return},
                {"right",     tt::Right},
                {"self",      tt::Self},
                {"set",       tt::Set},
                // tt::SetOpt
                {"static",    tt::Static},
                {"throw",     tt::Throw},
                {"throws",    tt::Throws},
                // tt::ThrowsOpt
                {"true",      tt::True},
                {"try",       tt::Try},
                // tt::TryExcl
                // tt::TryOpt
                {"use",       tt::Use},
                {"while",     tt::While},
                {"yield",     tt::Yield},
        };

        return keywords;
    }

    std::map<std::string, TokenType> getOperators() {
        static const std::map<std::string, TokenType> operators = {
                {"+", tt::Add},
                {"-", tt::Sub},
                {"*", tt::Mul},
                {"/", tt::Div},
                {"%", tt::Mod},
                {"**", tt::Pow},
                {"<<", tt::LSh},
                {">>", tt::RSh},

                {"<", tt::LT},
                {">", tt::GT},
                {"<=", tt::LE},
                {">=", tt::GE},
                {"==", tt::Eq},
                {"!=", tt::NE},
                {"===", tt::Id},
                {"!==", tt::NI},

                {"&&", tt::And},
                {"||", tt::Or},
                {"^^", tt::Xor},

                {"=", tt::Assign},
                {"+=", tt::AssignAdd},
                {"-=", tt::AssignSub},
                {"*=", tt::AssignMul},
                {"/=", tt::AssignDiv},
                {"%=", tt::AssignMod},
                {"**=", tt::AssignPow},
                {"<<=", tt::AssignLSh},
                {">>=", tt::AssignRSh},

                {"&", tt::Ampersand},
                {"|", tt::Pipe},
                {"^", tt::Hat},

                {"!", tt::ExclMark},
                {"?", tt::QuesMark},

                {":", tt::Colon},
                {"::", tt::DoubleColon},

                {"->", tt::RightArrow},
                {"~", tt::Tilde},
                {"~=", tt::TildeEq},
        };

        return operators;
    }

    class Lexer {
    private:
        size_t pos;
        size_t tok_start;

        size_t charno;
        size_t lineno;

        std::string buffer;
        std::vector<Token> tokens;
        std::stack<LexerState> states;

        void eat() {
            charno++;

            switch (buffer[++pos]) {
                case '\n':
                    states.push(s::NewLine);

                    break;

                case ' ':
                case '\t':
                    states.push(s::BuildToken);

                    break;

                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (states.top() != s::Integer && states.top() != s::Float) {
                        states.push(s::Integer);
                    }

                    break;

                case '<':
                    if(states.top() == s::DoubleDot) {
                        states.pop();
                        states.push(s::BuildToken);

                        break;
                    }

                case '=':
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '>':
                case '~':
                case '|':
                case '&':
                case '^':
                case '!':
                case '?':
                case ':':
                    if (states.top() != s::Operator) {
                        states.push(s::Operator);
                    }

                    break;

                case '.':
                    if (states.top() == s::Integer) {
                        states.pop();
                        states.push(s::Float);

                    } else if (states.top() == s::Dot) {
                        states.pop();
                        states.push(s::DoubleDot);

                    } else {
                        states.push(s::BuildToken);

                        pos--;
                        charno--;
                    }

                    break;

                case '\0':
                    states.push(s::Eof);// [TODO] Error in certain states (escapes and such).

                    break;

                default:
                    states.push(s::Error);

                    break;
            }
        }

        void build_token() {
            size_t tok_len = pos - tok_start;

            TokenType type;
            std::string val = buffer.substr(tok_start, tok_len);

            switch (states.top()) {
                case s::Integer:
                    type = tt::IntLiteral;

                    break;

                case s::Float:
                    type = tt::FloatLiteral;

                    break;

                case s::String:
                case s::StringEscape:
                    type = tt::StringLiteral;

                    break;// [TODO] Handle strings and their escapes.

                case s::Char:
                case s::CharEscape:
                    type = tt::CharLiteral;

                    break;// [TODO] Handle chars and their escapes.

                case s::Underscore:
                    type = tt::Underscore;

                    break;

                case s::Identifier: {
                    auto item = getKeywords().find(val);

                    if (item != getKeywords().end()) {
                        type = item->second;

                    } else {
                        type = tt::Identifier;
                    }
                }

                    break;

                case s::Operator: {
                    auto item = getOperators().find(val);

                    if (item != getOperators().end()) {
                        type = item->second;

                    } else {
                        type = tt::GeneralOperator;
                    }
                }

                    break;

                case s::Dollar:
                    type = tt::LambdaArg;

                    break;

                case s::Error:
                    type = tt::ErrorToken;

                    std::cerr << "[INTERNAL] Method `build_token` called in `Error` state." << std::endl;

                    break;

                default:
                    // [TODO] All other tokens...

                    break;
            }

            tokens.push_back(Token(type, val, lineno, charno - tok_len));
        }

    public:
        explicit Lexer(std::string buffer) : buffer(std::move(buffer)), states(std::stack<LexerState>()),
                                             tok_start(0), pos(0), charno(0), lineno(0),
                                             tokens(std::vector<Token>()) {
            states.push(s::Default);
        }

        Lexer(Lexer &parent) = default;

        ~Lexer() = default;

        LexError lex() {
            eat();

            switch (states.top()) {
                case s::NewLine:
                case s::BuildToken:
                    states.pop();

                    build_token();

                    tok_start.push(pos);

                    states.pop();

                    if (states.top() == s::NewLine)
                        lineno++;

                    break;

                case s::Error:
                    // [FIXME] To be implemented in `eat`.

                    break;

                default:
                    break;
            }
        }
    };
}


#endif //NODPARSER_LEXER_H
