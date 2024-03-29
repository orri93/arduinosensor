#ifndef _GOS_ARDUINO_LIBRARY_SENSOR_H_
#define _GOS_ARDUINO_LIBRARY_SENSOR_H_

#include <Arduino.h>

#define GOS_SENSOR_STATUS_OK            0
#define GOS_SENSOR_STATUS_ERROR         1
#define GOS_SENSOR_STATUS_BELOW_MINIMUM 2
#define GOS_SENSOR_STATUS_ABOVE_MAXIMUM 3

#define GOS_SENSOR_DEFAULT_MINIMUM -100.0
#define GOS_SENSOR_DEFAULT_MAXIMUM  100.0

namespace gos {
namespace sensor {
const char* error(const uint8_t& status, uint8_t& length);
const char* error(uint8_t& length);
extern double value;
namespace range {
uint8_t check(double& reading, const double& minimum, const double& maximum);
#ifndef GOS_SENSOR_GLOBAL_DISMISS
extern double Minimum;
extern double Maximum;
uint8_t check(double& reading);
#endif
}
}

#ifndef GOS_SENSOR_CLASS_DISMISS
class Sensor {
public:
  Sensor(const double& minimum, const double& maximum);
  uint8_t check(double& reading);

  double Minimum;
  double Maximum;
};
#endif
}

#endif /* _GOS_ARDUINO_LIBRARY_SENSOR_H_ */
