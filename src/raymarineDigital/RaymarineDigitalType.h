#ifdef INITIALIZE_RADAR

PLUGIN_BEGIN_NAMESPACE

static const NetworkAddress rm_report(224, 0, 0, 1, 5800);

PLUGIN_END_NAMESPACE

#endif

#define RANGE_METRIC_RT_RAYMARINE_DIGITAL \
  { 250, 500, 750, 1000, 1500, 2000, 3000, 4000, 6000, 8000, 12000, 16000, 24000, 36000, 48000, 64000 }
// Garmin mixed range is the same as nautical miles, it does not support really short ranges
#define RANGE_MIXED_RT_RAYMARINE_DIGITAL                                                                                   \
  {                                                                                                                        \
    1852 / 4, 1852 / 2, 1852 * 3 / 4, 1852 * 1, 1852 * 3 / 2, 1852 * 2, 1852 * 3, 1852 * 4, 1852 * 6, 1852 * 8, 1852 * 12, \
        1852 * 16, 1852 * 24, 1852 * 36, 1852 * 48                                                                         \
  }
#define RANGE_NAUTIC_RT_RAYMARINE_DIGITAL                                                                                  \
  {                                                                                                                        \
    1852 / 4, 1852 / 2, 1852 * 3 / 4, 1852 * 1, 1852 * 3 / 2, 1852 * 2, 1852 * 3, 1852 * 4, 1852 * 6, 1852 * 8, 1852 * 12, \
        1852 * 16, 1852 * 24, 1852 * 36, 1852 * 48                                                                         \
  }

#define RAYMARINE_DIGITAL_SPOKES 2048
#define RAYMARINE_DIGITAL_MAX_SPOKE_LEN 1024

#if SPOKES_MAX < RAYMARINE_DIGITAL_SPOKES
#undef SPOKES_MAX
#define SPOKES_MAX RAYMARINE_DIGITAL_SPOKES
#endif
#if SPOKE_LEN_MAX < RAYMARINE_DIGITAL_MAX_SPOKE_LEN
#undef SPOKE_LEN_MAX
#define SPOKE_LEN_MAX RAYMARINE_DIGITAL_MAX_SPOKE_LEN
#endif

DEFINE_RADAR(RT_RAYMARINE_DIGITAL,                       /* Type */
             wxT("Raymarine Digital"),                   /* Name */
             RAYMARINE_DIGITAL_SPOKES,                   /* Spokes */
             RAYMARINE_DIGITAL_MAX_SPOKE_LEN,            /* Spoke length */
             RaymarineDigitalControlsDialog,             /* Controls class */
             RaymarineDigitalReceive(pi, ri, rm_report), /* Receive class */
             RaymarineDigitalControl,                    /* Send/Control class */
             RO_SINGLE                                   /* This type only has a single radar and does not need locating */
)
