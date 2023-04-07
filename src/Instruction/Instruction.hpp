#ifndef __BOSONVM_INSTRUCTION_INSTRUCTION_HPP__
#define __BOSONVM_INSTRUCTION_INSTRUCTION_HPP__

#include <vector>
#include <ntl/NTL.hpp>
#include "Command.hpp"
#include "CommandFlag.hpp"
#include "../Misc/IndexedManager.hpp"

namespace bvm
{
    /// @brief 指令
    class NTL_ALIGN Instruction : public ntl::BasicObject
    {
    public:
        using SelfType = Instruction;
        using ParentType = BasicObject;

    public:
        /// @brief 指令
        Command::EnumType command = Command::None;

        /// @brief 标志0，一般放入参数长度，比如：CommandFlag::Byte
        CommandFlag::EnumType flag0 = CommandFlag::None;

        /// @brief 标志1，一般放入位置，比如：CommandFlag::Variables
        CommandFlag::EnumType flag1 = CommandFlag::None;

        /// @brief 参数
        ntl::Int64 argument = 0;

    public:
        constexpr Instruction() = default;
        explicit Instruction(Command::EnumType a_command,
                             ntl::Int64 argument = 0);
        explicit Instruction(Command::EnumType a_command,
                             CommandFlag::EnumType a_flag0,
                             ntl::Int64 argument = 0);
        explicit Instruction(Command::EnumType a_command,
                             CommandFlag::EnumType a_flag0,
                             CommandFlag::EnumType a_flag1,
                             ntl::Int64 argument = 0);
        constexpr explicit Instruction(const SelfType &from) = default;
        ~Instruction() = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) = default;
    };

    /// @brief 指令容器
    using InstructionContainer = std::vector<Instruction>;

    /// @brief 指令管理器
    using InstructionManager = IndexedManager<InstructionContainer>;

} // namespace bvm

namespace ntl
{
    Serialization serialize(const bvm::Instruction &instruction);

} // namespace ntl

#endif
