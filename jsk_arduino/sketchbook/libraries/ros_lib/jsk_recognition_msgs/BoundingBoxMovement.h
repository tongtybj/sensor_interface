#ifndef _ROS_jsk_recognition_msgs_BoundingBoxMovement_h
#define _ROS_jsk_recognition_msgs_BoundingBoxMovement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/BoundingBox.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"

namespace jsk_recognition_msgs
{

  class BoundingBoxMovement : public ros::Msg
  {
    public:
      std_msgs::Header header;
      jsk_recognition_msgs::BoundingBox box;
      geometry_msgs::Pose handle_pose;
      geometry_msgs::PoseStamped destination;

    BoundingBoxMovement():
      header(),
      box(),
      handle_pose(),
      destination()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->box.serialize(outbuffer + offset);
      offset += this->handle_pose.serialize(outbuffer + offset);
      offset += this->destination.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->box.deserialize(inbuffer + offset);
      offset += this->handle_pose.deserialize(inbuffer + offset);
      offset += this->destination.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/BoundingBoxMovement"; };
    const char * getMD5(){ return "60aeb288c030d1b8a67ddeedc91812f0"; };

  };

}
#endif