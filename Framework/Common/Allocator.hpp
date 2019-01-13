//
// Created by Hanxiang Ren on 2019-01-10.
//

#pragma once

#include <cstddef>
#include <cstdint>

namespace My {
    struct BlockHeader {
        BlockHeader *pNext;
    };

    struct PageHeader {
        PageHeader *pNext;
        BlockHeader* Blocks() {
            //this + 1 points to 8 bytes after the start of the struct.
            return reinterpret_cast<BlockHeader*>(this + 1);
        }
    };

    class Allocator {
    public:
        static const uint8_t PATTERN_ALIGN = 0xFC;
        static const uint8_t PATTERN_ALLOC = 0xFD;
        static const uint8_t PATTERN_FREE = 0xFE;

        Allocator (size_t data_size, size_t page_size, size_t alignment);
        ~Allocator();

        void Reset(size_t data_size, size_t page_size, size_t alignment);

        void* Allocate();
        void Free(void *p);
        void FreeAll();

    private:
#ifdef _DEBUG
        void FillFreePage(PageHeader* pPage);
        void FillFreeBlock(BlockHeader* pBlock);
        void FillAllocatedBlock(BlockHeader* pBlock);
#endif
        BlockHeader* NextBlock(BlockHeader* pBlock);
        PageHeader* m_pPageList;
        BlockHeader* m_pFreeList;

        size_t      m_szDataSize; // size of a
        size_t      m_szPageSize; // size of a page, header-size + data-size
        size_t      m_szAlignmentSize;
        size_t      m_szBlockSize;
        uint32_t    m_nBlocksPerPage;

        // statistics
        uint32_t    m_nPages;
        uint32_t    m_nBlocks;
        uint32_t    m_nFreeBlocks;

        Allocator (const Allocator& clone);
        Allocator& operator = (const Allocator& rhs);
    };
}

