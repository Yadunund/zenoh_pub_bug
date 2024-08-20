#pragma once

#include <gtest/gtest.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/set_bool.hpp"

using namespace testing;

class QosLatchedPublisher : public rclcpp::QoS {
 public:
  explicit QosLatchedPublisher(size_t depth = 1) : rclcpp::QoS(depth) { transient_local(); }
};

/// Instance of qos profile for latched publishers
static const QosLatchedPublisher rmw_qos_latched_publisher;

/* Testing fixture class */
class TestFixture : public ::testing::Test {
 public:
  /// Prepares the test
  void SetUp() override {
    test_node_ = std::make_shared<rclcpp::Node>("test_node");
    tx_string_ = test_node_->create_publisher<std_msgs::msg::String>(
        "/test_topic", rmw_qos_latched_publisher);
    test_client_ = test_node_->create_client<std_srvs::srv::SetBool>("/test_service");
  }

  std::shared_ptr<rclcpp::Node> test_node_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr tx_string_;
  rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr test_client_;
};