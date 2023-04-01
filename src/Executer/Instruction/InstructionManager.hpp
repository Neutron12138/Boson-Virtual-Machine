#ifndef __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_HPP__
#define __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_HPP__

#include <map>
#include <ntl/NTL.hpp>
#include "Instruction.hpp"

namespace bvm
{
    namespace Executer
    {
        /// @brief 指令管理器
        class InstructionManager : public ntl::Object
        {
        public:
            /// @brief 指令储存区
            using InstructionStorage = std::map<ntl::SizeT, InstructionContainer>;

            using SelfType = InstructionManager;
            using ParentType = ntl::Object;

        protected:
            /// @brief 指令储存区
            InstructionStorage m_Storage;

        public:
            InstructionManager() = default;
            explicit InstructionManager(const SelfType &from) = default;
            ~InstructionManager() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            SelfType &set_Storage(const InstructionStorage &Storage);
            const InstructionStorage &get_Storage() const;

        public:
            SelfType &add_instructions(ntl::SizeT index, const InstructionContainer &container);
            const InstructionContainer &get_instructions(ntl::SizeT index) const;
            bool is_index_existed(ntl::SizeT index) const;
        };

    } // namespace Executer

} // namespace bvm

#endif
