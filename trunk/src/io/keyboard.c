enum KBD_ENCODER_IO {
	INPUT_BUFFER     = 0x60,
	COMMAND_REGISTER = 0x60
};

enum KBD_CONTROL_IO {
	STATUS_REGISTER   = 0x64,
	COMMAND_REGISTER  = 0x64
};

// Possible values available on the status register
enum KBD_STATUS_MASK {
	// set if the buffer is full
	OUTPUT_BUFFER      = 0x01,
	// set if the buffer is full.  If full, the buffer cannot be written to
	INPUT_BUFFER       = 0x02,
	// set after self-test completed
	SELF_TEST_COMPLETE = 0x04,
	// set if last write to input buffer was a command
	COMMAND_DATA       = 0x08,
	// set if the keyboard is locked
	LOCKED             = 0x10,
	// can contain mouse data if value is not zero
	AUXILLIARY_BUFFER  = 0x20,
	// transmission timeout, may indicate parity errors
	TIMEOUT            = 0x40,
	// set if there was an error with the last byte
	PARITY_ERROR       = 0x80
};