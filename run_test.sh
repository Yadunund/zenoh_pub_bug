#!/bin/bash
source /opt/ros/$ROS_DISTRO/setup.bash
source install/setup.bash
unset ROS_DOMAIN_ID
colcon test --event-handlers console_cohesion+  console_direct+  --packages-select test_zenoh