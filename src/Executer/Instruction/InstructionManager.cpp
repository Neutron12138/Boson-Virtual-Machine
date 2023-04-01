#ifndef __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__
#define __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__

#include "InstructionManager.hpp"

namespace bvm
{
    namespace Executer
    {
        typename InstructionManager::SelfType &
        InstructionManager::set_Storage(
            const InstructionStorage &Storage)
        {
            m_Storage = Storage;
            return *this;
        }

        const typename InstructionManager::InstructionStorage &
        InstructionManager::get_Storage() const
        {
            return m_Storage;
        }

        typename InstructionManager::SelfType &
        InstructionManager::add_instructions(
            ntl::SizeT index,
            const InstructionContainer &container)
        {
            m_Storage.insert(
                InstructionStorage::value_type(
                    index,
                    container));
            return *this;
        }

        const InstructionContainer &
        InstructionManager::get_instructions(
            ntl::SizeT index) const
        {
            if (is_index_existed(index))
                return m_Storage.at(index);
            else
                throw ntl::OutOfRangeException(
                    ntl::StringUtils::to_string(
                        NTL_STRING("Index: "),
                        index,
                        NTL_STRING(" is not in storage")),
                    NTL_STRING("const InstructionContainer &InstructionManager::get_instructions(ntl::SizeT index) const"));
        }

        bool
        InstructionManager::is_index_existed(
            ntl::SizeT index) const
        {
            return m_Storage.find(index) != m_Storage.cend();
        }
    } // namespace Executer

} // namespace bvm

#endif
