// from ps1linux:include/asm-mipsnommu/flat.h, unsigned_long to uint32_t
// bFLT4's text_start disappearing makes header INCOMPATIBLE!
// they are NATIVE ENDIAN except flags, in contrast to bFLT4's network endian.
struct flat2_hdr {
	char magic[4];
	uint32_t rev;
	uint32_t entry_point; /* Offset of program start point from beginning of text segment */
	uint32_t text_start; /* Offset of first executable instruction with text segment from beginning of file*/
	uint32_t data_start; /* Offset of data segment from beginning of file*/

	uint32_t data_end; /* Offset of end of data segment from beginning of file*/
	uint32_t bss_end; /* Offset of end of bss segment from beginning of file*/
				/* (It is assumed that data_end through bss_end forms the
				    bss segment.) */
	uint32_t stack_size; /* Size of stack, in bytes */
	uint32_t reloc_start; /* Offset of relocation records from beginning of file */

	uint32_t reloc_count; /* Number of relocation records */

	uint32_t flags;

	uint32_t filler[5]; /* Reservered, set to zero */
};
#define	OLD_FLAT_VERSION		0x00000002L

#ifdef TARGET_mips
// ps1linux:include/asm-mipsnommu/flat.h, zero columns padded
// where the relocation target field in?
#define FLAT_RELOC_IN_TEXT       0x00000000
#define FLAT_RELOC_IN_DATA       0x40000000
#define FLAT_RELOC_IN_BSS        0x80000000
#define FLAT_RELOC_IN_MASK       0xc0000000
// where relocation value(symbol) is relative from?
#define FLAT_RELOC_REL_TEXT      0x00000000
#define FLAT_RELOC_REL_DATA      0x10000000
#define FLAT_RELOC_REL_BSS       0x20000000
#define FLAT_RELOC_REL_MASK      0x30000000
// e.g. a text referencing to a data: F_R_IN_TEXT | F_R_REL_DATA
// relocation type
#define FLAT_RELOC_TYPE_32       0x00000000
#define FLAT_RELOC_TYPE_HI16     0x01000000
#define FLAT_RELOC_TYPE_LO16     0x02000000
#define FLAT_RELOC_TYPE_26       0x03000000
#define FLAT_RELOC_TYPE_MASK     0x0f000000
// relocation direction
//#define FLAT_RELOC_SIGN_POS      0x00000000 // target+=rel_off
//#define FLAT_RELOC_SIGN_NEG      0x00800000 // target-=rel_off
//#define FLAT_RELOC_SIGN_MASK     0x00800000
#define FLAT_RELOC_OFFSET_MASK   0x007fffff
#endif
