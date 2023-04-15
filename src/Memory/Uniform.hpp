#ifndef __BOSONVM_MEMORY_UNIFORM_HPP__
#define __BOSONVM_MEMORY_UNIFORM_HPP__

#include <ntl/NTL.hpp>
#include "../Misc/IndexedManager.hpp"
#include "../Misc/Resource.hpp"

namespace bvm
{
    /// @brief 统一存储区
    class Uniform : public ntl::Object
    {
    public:
        /// @brief 数据持有者
        using DataHolder = std::vector<ntl::Byte>;

        using SelfType = Uniform;
        using ParentType = ntl::Object;

        /// @brief 权限
        enum Purview
        {
            /// @brief 虚拟机只能读取，不能修改
            ReadOnly = 0,

            /// @brief 可写入
            Writeable
        };

    protected:
        /// @brief 权限
        Purview m_purview = Purview::Writeable;

        /// @brief 数据持有者
        DataHolder m_holder;

    public:
        Uniform() = default;
        explicit Uniform(Purview purview);
        explicit Uniform(Purview purview, ntl::SizeT size);
        explicit Uniform(Purview purview, const DataHolder &holder);
        template <typename IteratorType>
        explicit Uniform(Purview purview, const IteratorType &begin, const IteratorType &end);
        explicit Uniform(const SelfType &from) = default;
        ~Uniform() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        SelfType &set_holder(const DataHolder &holder);
        SelfType &set_purview(Purview purview);

        const DataHolder &get_holder() const;
        Purview get_purview() const;

        ntl::SizeT size() const;

    public:
        ntl::Byte *get_data();
        const ntl::Byte *get_data() const;

        template <typename DataType>
        DataType *as(ntl::SizeT offset = 0);
        template <typename DataType>
        const DataType *as(ntl::SizeT offset = 0) const;
    };

    /// @brief 统一存储区管理器
    using UniformManager = IndexedManager<Uniform>;

    // 资源

    /// @brief 统一变量资源
    using UniformResource = Resource<Uniform>;

    /// @brief 统一存储区管理器资源
    using UniformManagerResource = Resource<UniformManager>;

} // namespace bvm

#endif
