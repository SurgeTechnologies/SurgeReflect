// Copyright (c) - SurgeTechnologies - All rights reserved
#pragma once
#include "SurgeReflect/Type.hpp"
#include "SurgeReflect/TypeTraits.hpp"
#include <string>

namespace SurgeReflect
{
    class Variable
    {
    public:
        Variable() = default;
        Variable(const std::string& name, AccessModifier accessModifier)
            : mName(name), mAccessModifier(accessModifier) {}

        const std::string& GetName() const { return mName; }
        const AccessModifier& GetAccessModifier() const { return mAccessModifier; }
        const uint64_t& GetSize() const { return mSize; }
        const Type& GetType() const { return mType; }

    private:
        template <auto Var>
        void Initialize()
        {
            using Traits = TypeTraits::VariableTraits<decltype(Var)>;
            mSize = sizeof(Traits::Type);
            mType.Initialize<Traits::Type>();
        }

    private:
        std::string mName;
        AccessModifier mAccessModifier;
        uint64_t mSize = 0;
        Type mType;

        friend class Class;
    };

} // namespace SurgeReflect