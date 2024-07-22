#include <stdint.h>

typedef struct {
	struct {
		union {
			struct {
				uint8_t F;
				uint8_t A;
			};

			uint16_t AF;
		};
	};

	struct {
		union {
			struct {
				uint8_t C;
				uint8_t B;
			};

			uint16_t BC;
		};
	};

	struct {
		union {
			struct {
				uint8_t E;
				uint8_t D;
			};

			uint16_t DE;
		};
	};

	struct {
		union {
			struct {
				uint8_t L;
				uint8_t H;
			};

			uint16_t HL;
		};
	};


	uint16_t PC; // Program Counter
	uint16_t SP; // Stack Pointer
} abRegisters;