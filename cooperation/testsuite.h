/** @file
 *	@brief MAVLink comm protocol testsuite generated from cooperation.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef COOPERATION_TESTSUITE_H
#define COOPERATION_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_cooperation(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_cooperation(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_cooperation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COOPERATION >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_cooperation_t packet_in = {
		93372036854775807ULL,179.0,235.0,291.0,241.0,269.0,297.0,137
    };
	mavlink_cooperation_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.usvTimestamp = packet_in.usvTimestamp;
        packet1.Lat = packet_in.Lat;
        packet1.Lon = packet_in.Lon;
        packet1.Alt = packet_in.Alt;
        packet1.Yaw = packet_in.Yaw;
        packet1.V = packet_in.V;
        packet1.Alt_d = packet_in.Alt_d;
        packet1.setting = packet_in.setting;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COOPERATION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COOPERATION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_cooperation_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_cooperation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_cooperation_pack(system_id, component_id, &msg , packet1.usvTimestamp , packet1.Lat , packet1.Lon , packet1.Alt , packet1.Yaw , packet1.V , packet1.Alt_d , packet1.setting );
	mavlink_msg_cooperation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_cooperation_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.usvTimestamp , packet1.Lat , packet1.Lon , packet1.Alt , packet1.Yaw , packet1.V , packet1.Alt_d , packet1.setting );
	mavlink_msg_cooperation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_cooperation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_cooperation_send(MAVLINK_COMM_1 , packet1.usvTimestamp , packet1.Lat , packet1.Lon , packet1.Alt , packet1.Yaw , packet1.V , packet1.Alt_d , packet1.setting );
	mavlink_msg_cooperation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cooperation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_cooperation(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // COOPERATION_TESTSUITE_H
