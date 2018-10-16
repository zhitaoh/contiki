#ifndef CC2420_JAMMER
#define CC2420_JAMMER

#define RX 0
#define TX 1
#define DROPLET 2
#define MOD 3
#define UNMOD 4
#define CH 5
#define DRIZZLE 6
#define OFF 7
#define TX2 8
#define REACT 9
#define LAST_MODE REACT
#define NUM_MODES (LAST_MODE+1)

#define CHANNEL 16
#define TXPOWER_LEVEL 23

#define TX_INTERVAL (CLOCK_SECOND / 1)
#define MAX_TX_PACKETS 1000
#define PAYLOAD_LEN 20
/* exprimental value used to occupy near full bandwidth, assuming RIMTER_SECOND = 4096 * N */
/* "SFD gap" = 298 us out of 4395 us Droplet interval => actual free air time = 298 - 160 (preamble+SFD) = 138 us => free bandwidth = 138/4395 = 3.1% */
/* #define DEFAULT_RTIMER_INTERVAL (RTIMER_SECOND / 128) */
#define RTIMER_INTERVAL ((RTIMER_SECOND + (225/2)) / 225 )
#define DST_ADDR0 2
#define DST_ADDR1 0

extern volatile int jam_ena;
extern const uint8_t jam_data[6];

int cc2420_set_frequency(uint16_t f);
uint16_t cc2420_get_frequency(void);
unsigned getreg(enum cc2420_register regname);
void setreg(enum cc2420_register regname, unsigned value);
void strobe(enum cc2420_register regname);
unsigned int status(void);
void flushrx(void);

void cc2420_set_rx_callback(void (*callback)(void));

#endif
