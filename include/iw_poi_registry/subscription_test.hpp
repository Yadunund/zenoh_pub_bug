#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/set_bool.hpp"

/**
 * @brief A test class that waits on a topic in its constructor
 */
class SubscriptionTest : public rclcpp::Node {
 public:
  /// Constructor
  explicit SubscriptionTest(const rclcpp::NodeOptions& options);

 private:
  void stringCallback(const std_msgs::msg::String& map_id);

  /// Subscriber for the map id
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr rx_string_;
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr srv_test_;

  std::string test_string_;
};
