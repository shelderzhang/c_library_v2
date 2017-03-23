// MESSAGE GESTURE PACKING

#define MAVLINK_MSG_ID_GESTURE 183

MAVPACKED(
typedef struct __mavlink_gesture_t {
 float reserved[3]; /*< reserved value*/
 uint8_t gesture_num; /*<  num of gesture identification*/
}) mavlink_gesture_t;

#define MAVLINK_MSG_ID_GESTURE_LEN 13
#define MAVLINK_MSG_ID_GESTURE_MIN_LEN 13
#define MAVLINK_MSG_ID_183_LEN 13
#define MAVLINK_MSG_ID_183_MIN_LEN 13

#define MAVLINK_MSG_ID_GESTURE_CRC 39
#define MAVLINK_MSG_ID_183_CRC 39

#define MAVLINK_MSG_GESTURE_FIELD_RESERVED_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GESTURE { \
	183, \
	"GESTURE", \
	2, \
	{  { "reserved", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_gesture_t, reserved) }, \
         { "gesture_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gesture_t, gesture_num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GESTURE { \
	"GESTURE", \
	2, \
	{  { "reserved", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_gesture_t, reserved) }, \
         { "gesture_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gesture_t, gesture_num) }, \
         } \
}
#endif

/**
 * @brief Pack a gesture message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gesture_num  num of gesture identification
 * @param reserved reserved value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gesture_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t gesture_num, const float *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GESTURE_LEN];
	_mav_put_uint8_t(buf, 12, gesture_num);
	_mav_put_float_array(buf, 0, reserved, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GESTURE_LEN);
#else
	mavlink_gesture_t packet;
	packet.gesture_num = gesture_num;
	mav_array_memcpy(packet.reserved, reserved, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GESTURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GESTURE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
}

/**
 * @brief Pack a gesture message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gesture_num  num of gesture identification
 * @param reserved reserved value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gesture_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t gesture_num,const float *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GESTURE_LEN];
	_mav_put_uint8_t(buf, 12, gesture_num);
	_mav_put_float_array(buf, 0, reserved, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GESTURE_LEN);
#else
	mavlink_gesture_t packet;
	packet.gesture_num = gesture_num;
	mav_array_memcpy(packet.reserved, reserved, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GESTURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GESTURE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
}

/**
 * @brief Encode a gesture struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gesture C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gesture_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gesture_t* gesture)
{
	return mavlink_msg_gesture_pack(system_id, component_id, msg, gesture->gesture_num, gesture->reserved);
}

/**
 * @brief Encode a gesture struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gesture C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gesture_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gesture_t* gesture)
{
	return mavlink_msg_gesture_pack_chan(system_id, component_id, chan, msg, gesture->gesture_num, gesture->reserved);
}

/**
 * @brief Send a gesture message
 * @param chan MAVLink channel to send the message
 *
 * @param gesture_num  num of gesture identification
 * @param reserved reserved value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gesture_send(mavlink_channel_t chan, uint8_t gesture_num, const float *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GESTURE_LEN];
	_mav_put_uint8_t(buf, 12, gesture_num);
	_mav_put_float_array(buf, 0, reserved, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GESTURE, buf, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
#else
	mavlink_gesture_t packet;
	packet.gesture_num = gesture_num;
	mav_array_memcpy(packet.reserved, reserved, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GESTURE, (const char *)&packet, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
#endif
}

/**
 * @brief Send a gesture message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gesture_send_struct(mavlink_channel_t chan, const mavlink_gesture_t* gesture)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gesture_send(chan, gesture->gesture_num, gesture->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GESTURE, (const char *)gesture, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
#endif
}

#if MAVLINK_MSG_ID_GESTURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gesture_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t gesture_num, const float *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 12, gesture_num);
	_mav_put_float_array(buf, 0, reserved, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GESTURE, buf, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
#else
	mavlink_gesture_t *packet = (mavlink_gesture_t *)msgbuf;
	packet->gesture_num = gesture_num;
	mav_array_memcpy(packet->reserved, reserved, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GESTURE, (const char *)packet, MAVLINK_MSG_ID_GESTURE_MIN_LEN, MAVLINK_MSG_ID_GESTURE_LEN, MAVLINK_MSG_ID_GESTURE_CRC);
#endif
}
#endif

#endif

// MESSAGE GESTURE UNPACKING


/**
 * @brief Get field gesture_num from gesture message
 *
 * @return  num of gesture identification
 */
static inline uint8_t mavlink_msg_gesture_get_gesture_num(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field reserved from gesture message
 *
 * @return reserved value
 */
static inline uint16_t mavlink_msg_gesture_get_reserved(const mavlink_message_t* msg, float *reserved)
{
	return _MAV_RETURN_float_array(msg, reserved, 3,  0);
}

/**
 * @brief Decode a gesture message into a struct
 *
 * @param msg The message to decode
 * @param gesture C-struct to decode the message contents into
 */
static inline void mavlink_msg_gesture_decode(const mavlink_message_t* msg, mavlink_gesture_t* gesture)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_gesture_get_reserved(msg, gesture->reserved);
	gesture->gesture_num = mavlink_msg_gesture_get_gesture_num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GESTURE_LEN? msg->len : MAVLINK_MSG_ID_GESTURE_LEN;
        memset(gesture, 0, MAVLINK_MSG_ID_GESTURE_LEN);
	memcpy(gesture, _MAV_PAYLOAD(msg), len);
#endif
}
