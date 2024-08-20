#include "iw_poi_registry/subscription_test.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto registry_node = std::make_shared<SubscriptionTest>(rclcpp::NodeOptions());

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(registry_node->get_node_base_interface());
  executor.spin();

  rclcpp::shutdown();
  return 0;
}