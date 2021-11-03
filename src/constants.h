#pragma once
#ifndef TG_VISIBILITY_INTERNAL

typedef enum {
    Public,
    Internal,
    Private,
    Protected,
    ProtectedInternal
} TgVisibility;

typedef enum {
    Default,
    Static,
    Abstract,
    Native,
    Final
} TgMembtype;

#define TG_VISIBILITY_INTERNAL 0
#define TG_VISIBILITY_PUBLIC 1
#define TG_VISIBILITY_PRIVATE 2
#define TG_VISIBILITY_PROTECTED 3
#define TG_VISIBILITY_PROTECTED_INTERNAL 4

#define TG_MEMBTYPE_DEFAULT 0
#define TG_MEMBTYPE_STATIC 1
#define TG_MEMBTYPE_ABSTRACT 2
#define TG_MEMBTYPE_NATIVE 3
#define TG_MEMBTYPE_FINAL 4

#endif
