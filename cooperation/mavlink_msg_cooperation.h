// MESSAGE COOPERATION PACKING

#define MAVLINK_MSG_ID_COOPERATION 182

MAVPACKED(
typedef struct __mavlink_cooperation_t {
 uint64_t usvTimestamp; /*< Timestamp (micros since boot or Unix epoch)*/
 double Lat; /*< Latitude of ugv*/
 double Lon; /*< Lontitude of ugv*/
 double Alt; /*< Altitude of ugv*/
 float Yaw; /*< Yaw of ugv*/
 float V; /*< Total velocity of ugv*/
 float Alt_d; /*< desired altitude of ugv*/
 uint8_t setting; /*< settint mode*/
}) mavlink_cooperation_t;

#define MAVLINK_MSG_ID_COOPERATION_LEN 45
#define MAVLINK_MSG_ID_COOPERATION_MIN_LEN 45
#define MAVLINK_MSG_ID_182_LEN 45
#define MAVLINK_MSG_ID_182_MIN_LEN 45

#define MAVLINK_MSG_ID_COOPERATION_CRC 107
#define MAVLINK_MSG_ID_182_CRC 107



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COOPERATION { \
	182, \
	"COOPERATION", \
	8, \
	{  { "usvTimestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cooperation_t, usvTimestamp) }, \
         { "Lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_cooperation_t, Lat) }, \
         { "Lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_cooperation_t, Lon) }, \
         { "Alt", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_cooperation_t, Alt) }, \
         { "Yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_cooperation_t, Yaw) }, \
         { "V", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_cooperation_t, V) }, \
         { "Alt_d", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_cooperation_t, Alt_d) }, \
         { "setting", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_cooperation_t, setting) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COOPERATION { \
	"COOPERATION", \
	8, \
	{  { "usvTimestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cooperation_t, usvTimestamp) }, \
         { "Lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_cooperation_t, Lat) }, \
         { "Lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_cooperation_t, Lon) }, \
         { "Alt", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_cooperation_t, Alt) }, \
         { "Yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_cooperation_t, Yaw) }, \
         { "V", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_cooperation_t, V) }, \
         { "Alt_d", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_cooperation_t, Alt_d) }, \
         { "setting", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_cooperation_t, setting) }, \
         } \
}
#endif

/**
 * @brief Pack a cooperation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usvTimestamp Timestamp (micros since boot or Unix epoch)
 * @param Lat Latitude of ugv
 * @param Lon Lontitude of ugv
 * @param Alt Altitude of ugv
 * @param Yaw Yaw of ugv
 * @param V Total velocity of ugv
 * @param Alt_d desired altitude of ugv
 * @param setting settint mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cooperation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usvTimestamp, double Lat, double Lon, double Alt, float Yaw, float V, float Alt_d, uint8_t setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COOPERATION_LEN];
	_mav_put_uint64_t(buf, 0, usvTimestamp);
	_mav_put_double(buf, 8, Lat);
	_mav_put_double(buf, 16, Lon);
	_mav_put_double(buf, 24, Alt);
	_mav_put_float(buf, 32, Yaw);
	_mav_put_float(buf, 36, V);
	_mav_put_float(buf, 40, Alt_d);
	_mav_put_uint8_t(buf, 44, setting);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COOPERATION_LEN);
#else
	mavlink_cooperation_t packet;
	packet.usvTimestamp = usvTimestamp;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Yaw = Yaw;
	packet.V = V;
	packet.Alt_d = Alt_d;
	packet.setting = setting;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COOPERATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COOPERATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
}

/**
 * @brief Pack a cooperation message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usvTimestamp Timestamp (micros since boot or Unix epoch)
 * @param Lat Latitude of ugv
 * @param Lon Lontitude of ugv
 * @param Alt Altitude of ugv
 * @param Yaw Yaw of ugv
 * @param V Total velocity of ugv
 * @param Alt_d desired altitude of ugv
 * @param setting settint mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cooperation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usvTimestamp,double Lat,double Lon,double Alt,float Yaw,float V,float Alt_d,uint8_t setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COOPERATION_LEN];
	_mav_put_uint64_t(buf, 0, usvTimestamp);
	_mav_put_double(buf, 8, Lat);
	_mav_put_double(buf, 16, Lon);
	_mav_put_double(buf, 24, Alt);
	_mav_put_float(buf, 32, Yaw);
	_mav_put_float(buf, 36, V);
	_mav_put_float(buf, 40, Alt_d);
	_mav_put_uint8_t(buf, 44, setting);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COOPERATION_LEN);
#else
	mavlink_cooperation_t packet;
	packet.usvTimestamp = usvTimestamp;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Yaw = Yaw;
	packet.V = V;
	packet.Alt_d = Alt_d;
	packet.setting = setting;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COOPERATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COOPERATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
}

/**
 * @brief Encode a cooperation struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cooperation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cooperation_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cooperation_t* cooperation)
{
	return mavlink_msg_cooperation_pack(system_id, component_id, msg, cooperation->usvTimestamp, cooperation->Lat, cooperation->Lon, cooperation->Alt, cooperation->Yaw, cooperation->V, cooperation->Alt_d, cooperation->setting);
}

/**
 * @brief Encode a cooperation struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cooperation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cooperation_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cooperation_t* cooperation)
{
	return mavlink_msg_cooperation_pack_chan(system_id, component_id, chan, msg, cooperation->usvTimestamp, cooperation->Lat, cooperation->Lon, cooperation->Alt, cooperation->Yaw, cooperation->V, cooperation->Alt_d, cooperation->setting);
}

/**
 * @brief Send a cooperation message
 * @param chan MAVLink channel to send the message
 *
 * @param usvTimestamp Timestamp (micros since boot or Unix epoch)
 * @param Lat Latitude of ugv
 * @param Lon Lontitude of ugv
 * @param Alt Altitude of ugv
 * @param Yaw Yaw of ugv
 * @param V Total velocity of ugv
 * @param Alt_d desired altitude of ugv
 * @param setting settint mode
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cooperation_send(mavlink_channel_t chan, uint64_t usvTimestamp, double Lat, double Lon, double Alt, float Yaw, float V, float Alt_d, uint8_t setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COOPERATION_LEN];
	_mav_put_uint64_t(buf, 0, usvTimestamp);
	_mav_put_double(buf, 8, Lat);
	_mav_put_double(buf, 16, Lon);
	_mav_put_double(buf, 24, Alt);
	_mav_put_float(buf, 32, Yaw);
	_mav_put_float(buf, 36, V);
	_mav_put_float(buf, 40, Alt_d);
	_mav_put_uint8_t(buf, 44, setting);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COOPERATION, buf, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
#else
	mavlink_cooperation_t packet;
	packet.usvTimestamp = usvTimestamp;
	packet.Lat = Lat;
	packet.Lon = Lon;
	packet.Alt = Alt;
	packet.Yaw = Yaw;
	packet.V = V;
	packet.Alt_d = Alt_d;
	packet.setting = setting;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COOPERATION, (const char *)&packet, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
#endif
}

/**
 * @brief Send a cooperation message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cooperation_send_struct(mavlink_channel_t chan, const mavlink_cooperation_t* cooperation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cooperation_send(chan, cooperation->usvTimestamp, cooperation->Lat, cooperation->Lon, cooperation->Alt, cooperation->Yaw, cooperation->V, cooperation->Alt_d, cooperation->setting);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COOPERATION, (const char *)cooperation, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_COOPERATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cooperation_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usvTimestamp, double Lat, double Lon, double Alt, float Yaw, float V, float Alt_d, uint8_t setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, usvTimestamp);
	_mav_put_double(buf, 8, Lat);
	_mav_put_double(buf, 16, Lon);
	_mav_put_double(buf, 24, Alt);
	_mav_put_float(buf, 32, Yaw);
	_mav_put_float(buf, 36, V);
	_mav_put_float(buf, 40, Alt_d);
	_mav_put_uint8_t(buf, 44, setting);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COOPERATION, buf, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
#else
	mavlink_cooperation_t *packet = (mavlink_cooperation_t *)msgbuf;
	packet->usvTimestamp = usvTimestamp;
	packet->Lat = Lat;
	packet->Lon = Lon;
	packet->Alt = Alt;
	packet->Yaw = Yaw;
	packet->V = V;
	packet->Alt_d = Alt_d;
	packet->setting = setting;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COOPERATION, (const char *)packet, MAVLINK_MSG_ID_COOPERATION_MIN_LEN, MAVLINK_MSG_ID_COOPERATION_LEN, MAVLINK_MSG_ID_COOPERATION_CRC);
#endif
}
#endif

#endif

// MESSAGE COOPERATION UNPACKING


/**
 * @brief Get field usvTimestamp from cooperation message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_cooperation_get_usvTimestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Lat from cooperation message
 *
 * @return Latitude of ugv
 */
static inline double mavlink_msg_cooperation_get_Lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field Lon from cooperation message
 *
 * @return Lontitude of ugv
 */
static inline double mavlink_msg_cooperation_get_Lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field Alt from cooperation message
 *
 * @return Altitude of ugv
 */
static inline double mavlink_msg_cooperation_get_Alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Get field Yaw from cooperation message
 *
 * @return Yaw of ugv
 */
static inline float mavlink_msg_cooperation_get_Yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field V from cooperation message
 *
 * @return Total velocity of ugv
 */
static inline float mavlink_msg_cooperation_get_V(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field Alt_d from cooperation message
 *
 * @return desired altitude of ugv
 */
static inline float mavlink_msg_cooperation_get_Alt_d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field setting from cooperation message
 *
 * @return settint mode
 */
static inline uint8_t mavlink_msg_cooperation_get_setting(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Decode a cooperation message into a struct
 *
 * @param msg The message to decode
 * @param cooperation C-struct to decode the message contents into
 */
static inline void mavlink_msg_cooperation_decode(const mavlink_message_t* msg, mavlink_cooperation_t* cooperation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	cooperation->usvTimestamp = mavlink_msg_cooperation_get_usvTimestamp(msg);
	cooperation->Lat = mavlink_msg_cooperation_get_Lat(msg);
	cooperation->Lon = mavlink_msg_cooperation_get_Lon(msg);
	cooperation->Alt = mavlink_msg_cooperation_get_Alt(msg);
	cooperation->Yaw = mavlink_msg_cooperation_get_Yaw(msg);
	cooperation->V = mavlink_msg_cooperation_get_V(msg);
	cooperation->Alt_d = mavlink_msg_cooperation_get_Alt_d(msg);
	cooperation->setting = mavlink_msg_cooperation_get_setting(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COOPERATION_LEN? msg->len : MAVLINK_MSG_ID_COOPERATION_LEN;
        memset(cooperation, 0, MAVLINK_MSG_ID_COOPERATION_LEN);
	memcpy(cooperation, _MAV_PAYLOAD(msg), len);
#endif
}
