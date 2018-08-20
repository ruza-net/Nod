//
// Created by Jan Růžička on 11/08/2018.
//

#ifndef NODPARSER_TOKEN_H
#define NODPARSER_TOKEN_H

#include <string>


namespace Nod
{
    enum class TokenType {

        // Literals
        //
        LambdaArg,
        Identifier,
        IntLiteral,
        FloatLiteral,
        CharLiteral,
        StringLiteral,
        GeneralOperator,

        // [AREA] Symbols

        // Basic Operators
        //
        //                                token        custom operator
        Add,//                              +               yes
        Sub,//                              -               yes
        Mul,//                              *               yes
        Div,//                              /               yes
        Mod,//                              %               yes
        Pow,//                              **              yes
        LSh,//                              <<              yes
        RSh,//                              >>              yes

        // Comparison Operators
        //
        LT,//                               <               yes
        GT,//                               >               yes
        LE,//                               <=              yes
        GE,//                               >=              yes
        NE,//                               !=              yes
        Eq,//                               ==              yes
        Id,//                               ===             yes
        NI,//                               !==             yes

        // Logical Operators
        //
        And,//                              &&              yes
        Or,//                               ||              yes
        Xor,//                              ^^              yes

        // Assignment Operators
        //
        Assign,//                           =               long only
        AssignAdd,//                        +=              long only
        AssignSub,//                        -=              long only
        AssignMul,//                        *=              long only
        AssignDiv,//                        /=              long only
        AssignMod,//                        %=              long only
        AssignPow,//                        **=             long only
        AssignLSh,//                        <<=             long only
        AssignRSh,//                        >>=             long only

        // Control Operators
        //
        Underscore,//                       _               no
        Ampersand,//                        &               yes
        Pipe,//                             |               yes
        Hat,//                              ^               yes
        ExclMark,//                         !               yes
        QuesMark,//                         ?               long only
        Colon,//                            :               long only
        DoubleColon,//                      ::              long only
        Semicolon,//                        ;               no
        Comma,//                            ,               no
        Dot,//                              .               no
        DoubleDot,//                        ..              no
        DoubleDotLT,//                      ..<             no
        RightArrow,//                       ->              long only
        Tilde,//                            ~               long only
        TildeEq,//                          ~=              long only

        // Parenthesis
        //
        ParenL,//                           (               no
        ParenR,//                           )               no
        BracketL,//                         [               no
        BracketR,//                         ]               no
        BraceL,//                           {               no
        BraceR,//                           }               no

        // [END] Symbols

        // [AREA] Keywords

        As,
        Attr,
        Break,
        Case,
        Catch,
        Class,
        Continue,
        Del,
        DelOpt,// [FIXME] Functional vs. Shorthand Imperative (see `conflict.md`)
        Do,
        Else,
        Enum,
        False,
        For,
        Func,
        Gen,
        Get,
        GetOpt,// [FIXME] Is this necessary? Seems like it's covered by `pub?`
        Guard,
        If,
        In,
        InOpt,// [FIXME] Functional vs. Shorthand Imperative (see `conflict.md`)
        Infix,
        Init,
        InitAmp,
        InitOpt,
        Inline,
        Left,
        Let,
        LetAmp,// [FIXME] Is this necessary? Seems like it's covered in type declaration.
        LetOpt,// [FIXME] Is this necessary? Seems like it's covered in type declaration.
        Loop,
        Match,
        Mut,
        Namespace,
        Postfix,
        Prefix,
        Protocol,
        Pub,
        PubOpt,
        Return,
        Right,
        Self,
        // [TODO] Make keyword for typename of current instance in `protocol` declarations (like `Self` in Swift).
        Set,
        SetOpt,
        Static,
        Throw,
        Throws,
        ThrowsOpt,
        True,
        Try,
        TryExcl,
        TryOpt,// [FIXME] Functional vs. Shorthand Imperative (see `conflict.md`)
        Use,
        While,
        Yield,

        // [END] Keywords

        ErrorToken,
    };

    using tt = TokenType;


    class Token {
    private:
        TokenType kind;

        std::string value;

        size_t lineno;
        size_t charno;

    public:
        Token(TokenType k, std::string v, size_t l, size_t c) : kind(k), value(std::move(v)), lineno(l), charno(c) {}

        Token(Token const &other) = default;

        Token(Token &&other) = default;

        ~Token() = default;

        Token &operator=(Token const &other) = default;

        Token &operator=(Token &&other) = default;
    };
}

#endif //NODPARSER_TOKEN_H
