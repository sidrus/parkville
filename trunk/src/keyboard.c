enum KBD_ENCODER_IO {
	ENC_IO_INPUT_BUFFER     = 0x60,
	ENC_IO_COMMAND_REGISTER = 0x60
};

enum KBD_CONTROL_IO {
	CTL_IO_STATUS_REGISTER   = 0x64,
	CTL_IO_COMMAND_REGISTER = 0x64
};

// Possible values available on the status register
enum KBD_STATUS_MASK {
	// set if the buffer is full
	STAT_OUTPUT_BUFFER      = 0x01,
	// set if the buffer is full.  If full, the buffer cannot be written to
	STAT_INPUT_BUFFER       = 0x02,
	// set after self-test completed
	STAT_SELF_TEST_COMPLETE = 0x04,
	// set if last write to input buffer was a command
	STAT_COMMAND_DATA       = 0x08,
	// set if the keyboard is locked
	STAT_LOCKED             = 0x10,
	// can contain mouse data if value is not zero
	STAT_AUXILLIARY_BUFFER  = 0x20,
	// transmission timeout, may indicate parity errors
	STAT_TIMEOUT            = 0x40,
	// set if there was an error with the last byte
	STAT_PARITY_ERROR       = 0x80
};



