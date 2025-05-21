/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_XIP_CTRL_H
#define HW_XIP_CTRL_H
/** QSPI flash execute-in-place block */
/** Interrupt : XIP_IRQ (Vector: 6)  */
/** Memory Block starting at 0x14000000 + 0x0 is 0x20 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define XIP_CTRL_CTRL_POWER_DOWN_OFFSET                    3u
#define XIP_CTRL_CTRL_POWER_DOWN_MASK                      8u

#define XIP_CTRL_CTRL_ERR_BADWRITE_OFFSET                  1u
#define XIP_CTRL_CTRL_ERR_BADWRITE_MASK                    2u

#define XIP_CTRL_CTRL_EN_OFFSET                            0u
#define XIP_CTRL_CTRL_EN_MASK                              1u

#define XIP_CTRL_FLUSH_FLUSH_OFFSET                        0u
#define XIP_CTRL_FLUSH_FLUSH_MASK                          1u

#define XIP_CTRL_STAT_FIFO_FULL_OFFSET                     2u
#define XIP_CTRL_STAT_FIFO_FULL_MASK                       4u

#define XIP_CTRL_STAT_FIFO_EMPTY_OFFSET                    1u
#define XIP_CTRL_STAT_FIFO_EMPTY_MASK                      2u

#define XIP_CTRL_STAT_FLUSH_READY_OFFSET                   0u
#define XIP_CTRL_STAT_FLUSH_READY_MASK                     1u

#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR_OFFSET            2u
#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR_MASK              0xfffffffcu

#define XIP_CTRL_STREAM_CTR_STREAM_CTR_OFFSET              0u
#define XIP_CTRL_STREAM_CTR_STREAM_CTR_MASK                0x3fffffu


typedef struct
{

/** CTRL (offset: 0x0)
  Cache control
  access : read-write
  reset value : 0x3
  reset mask : 0x0
  Field: POWER_DOWN
  offset: 3, size: 1, access: read-write
  When 1, the cache memories are powered down. They retain state,

 but can not be accessed. This reduces static power dissipation.

 Writing 1 to this bit forces CTRL_EN to 0, i.e. the cache cannot

 be enabled when powered down.

 Cache-as-SRAM accesses will produce a bus error response when

 the cache is powered down.
  Field: ERR_BADWRITE
  offset: 1, size: 1, access: read-write
  When 1, writes to any alias other than 0x0 (caching, allocating)

 will produce a bus fault. When 0, these writes are silently ignored.

 In either case, writes to the 0x0 alias will deallocate on tag match,

 as usual.
  Field: EN
  offset: 0, size: 1, access: read-write
  When 1, enable the cache. When the cache is disabled, all XIP accesses

 will go straight to the flash, without querying the cache. When enabled,

 cacheable XIP accesses will query the cache, and the flash will

 not be accessed if the tag matches and the valid bit is set.


 If the cache is enabled, cache-as-SRAM accesses have no effect on the

 cache data RAM, and will produce a bus error response.
*/
volatile uint32_t CTRL;

/** FLUSH (offset: 0x4)
  Cache Flush control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FLUSH
  offset: 0, size: 1, access: read-write
  Write 1 to flush the cache. This clears the tag memory, but

 the data memory retains its contents. (This means cache-as-SRAM

 contents is not affected by flush or reset.)

 Reading will hold the bus (stall the processor) until the flush

 completes. Alternatively STAT can be polled until completion.
*/
volatile uint32_t FLUSH;

/** STAT (offset: 0x8)
  Cache Status
  access : read-write
  reset value : 0x2
  reset mask : 0x0
  Field: FIFO_FULL
  offset: 2, size: 1, access: read-only
  When 1, indicates the XIP streaming FIFO is completely full.

 The streaming FIFO is 2 entries deep, so the full and empty

 flag allow its level to be ascertained.
  Field: FIFO_EMPTY
  offset: 1, size: 1, access: read-only
  When 1, indicates the XIP streaming FIFO is completely empty.
  Field: FLUSH_READY
  offset: 0, size: 1, access: read-only
  Reads as 0 while a cache flush is in progress, and 1 otherwise.

 The cache is flushed whenever the XIP block is reset, and also

 when requested via the FLUSH register.
*/
volatile uint32_t STAT;

/** CTR_HIT (offset: 0xc)
  Cache Hit counter

 A 32 bit saturating counter that increments upon each cache hit,

 i.e. when an XIP access is serviced directly from cached data.

 Write any value to clear.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CTR_HIT;

/** CTR_ACC (offset: 0x10)
  Cache Access counter

 A 32 bit saturating counter that increments upon each XIP access,

 whether the cache is hit or not. This includes noncacheable accesses.

 Write any value to clear.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CTR_ACC;

/** STREAM_ADDR (offset: 0x14)
  FIFO stream address
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: STREAM_ADDR
  offset: 2, size: 30, access: read-write
  The address of the next word to be streamed from flash to the streaming FIFO.

 Increments automatically after each flash access.

 Write the initial access address here before starting a streaming read.
*/
volatile uint32_t STREAM_ADDR;

/** STREAM_CTR (offset: 0x18)
  FIFO stream control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: STREAM_CTR
  offset: 0, size: 22, access: read-write
  Write a nonzero value to start a streaming read. This will then

 progress in the background, using flash idle cycles to transfer

 a linear data block from flash to the streaming FIFO.

 Decrements automatically (1 at a time) as the stream

 progresses, and halts on reaching 0.

 Write 0 to halt an in-progress stream, and discard any in-flight

 read, so that a new stream can immediately be started (after

 draining the FIFO and reinitialising STREAM_ADDR)
*/
volatile uint32_t STREAM_CTR;

/** STREAM_FIFO (offset: 0x1c)
  FIFO stream data

 Streamed data is buffered here, for retrieval by the system DMA.

 This FIFO can also be accessed via the XIP_AUX slave, to avoid exposing

 the DMA to bus stalls caused by other XIP traffic.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t STREAM_FIFO;
} XIP_CTRL_type;

#define XIP_CTRL ((XIP_CTRL_type *) 0x14000000)

#endif // HW_XIP_CTRL_H
