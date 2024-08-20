#include "iw_poi_registry/subscription_test.hpp"

using namespace std::chrono_literals;

/// Qos profile for latched subscribers
class QosLatchedSubscriber : public rclcpp::QoS {
 public:
  explicit QosLatchedSubscriber(size_t depth = 10) : rclcpp::QoS(depth) { transient_local(); }
};

/// Instance of Qos profile for latched subscribers
static const QosLatchedSubscriber rmw_qos_latched_subscriber;

SubscriptionTest::SubscriptionTest(const rclcpp::NodeOptions& options)
    : rclcpp::Node("subscription_test", options) {
  rx_string_ = create_subscription<std_msgs::msg::String>("/test_topic", rmw_qos_latched_subscriber,
      std::bind(&SubscriptionTest::stringCallback, this, std::placeholders::_1));
  RCLCPP_INFO(get_logger(), "test starting, waiting string...");
  while (test_string_.empty()) {
    std::this_thread::sleep_for(100ms);
    rclcpp::spin_some(get_node_base_interface());
    RCLCPP_INFO_STREAM_THROTTLE(
        get_logger(), *(get_clock()), 1000, "Waiting for test topic to be published...");
  }
  srv_test_ = create_service<std_srvs::srv::SetBool>(
      "/test_service",
      [this](const std_srvs::srv::SetBool::Request::SharedPtr request,
          const std_srvs::srv::SetBool::Response::SharedPtr response) {
        RCLCPP_INFO(get_logger(), "Got a request");
        (void)request;
        (void)response;
      },
      rclcpp::QoS(2), nullptr);
  RCLCPP_INFO(get_logger(), "Test class constructed");
}

void SubscriptionTest::stringCallback(const std_msgs::msg::String& test_string) {
  test_string_ = test_string.data;
}