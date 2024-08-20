This test will randomly fail when using ZenohRmw, and always succeed using Cyclone DDS

# Compilation 

colcon build

(eventually fetch rosdeps)

# Execution 

From the root of your workspace, execute the run_test.sh script

# Output when failing 

```
1: [subscription_test_exe-1] [INFO] [1724167333.685161728] [rmw_zenoh_cpp]: Successfully connected to a Zenoh router with id 836cf11bb72bc56bdb3083b86c4cf067.
1: [test_subscription-2] [INFO] [1724167333.687056195] [rmw_zenoh_cpp]: Successfully connected to a Zenoh router with id 836cf11bb72bc56bdb3083b86c4cf067.
1: [test_subscription-2] [==========] Running 1 test from 1 test suite.
1: [test_subscription-2] [----------] Global test environment set-up.
1: [test_subscription-2] [----------] 1 test from TestFixture
1: [test_subscription-2] [ RUN      ] TestFixture.testPubString
1: [subscription_test_exe-1] [INFO] [1724167334.689553118] [subscription_test]: test starting, waiting string...
1: [subscription_test_exe-1] [INFO] [1724167334.789846083] [subscription_test]: Waiting for test topic to be published...
1: [subscription_test_exe-1] [INFO] [1724167335.791367092] [subscription_test]: Waiting for test topic to be published...
1: [subscription_test_exe-1] [INFO] [1724167336.792940620] [subscription_test]: Waiting for test topic to be published...
1: [subscription_test_exe-1] [INFO] [1724167337.794388354] [subscription_test]: Waiting for test topic to be published...
1: [subscription_test_exe-1] [INFO] [1724167338.796174442] [subscription_test]: Waiting for test topic to be published...
1: [test_subscription-2] /home/user/ros2_ws/src/brain/test_zenoh/test/test_pub_string.cpp:17: Failure
1: [test_subscription-2] Value of: test_client_->wait_for_service(5s)
1: [test_subscription-2]   Actual: false
1: [test_subscription-2] Expected: true
```


# Output when succeeding 

```
 [test_subscription-2] [INFO] [1724167329.190153490] [rmw_zenoh_cpp]: Successfully connected to a Zenoh router with id 836cf11bb72bc56bdb3083b86c4cf067.
1: [subscription_test_exe-1] [INFO] [1724167329.198294686] [rmw_zenoh_cpp]: Successfully connected to a Zenoh router with id 836cf11bb72bc56bdb3083b86c4cf067.
1: [test_subscription-2] [==========] Running 1 test from 1 test suite.
1: [test_subscription-2] [----------] Global test environment set-up.
1: [test_subscription-2] [----------] 1 test from TestFixture
1: [test_subscription-2] [ RUN      ] TestFixture.testPubString
1: [subscription_test_exe-1] [INFO] [1724167330.204746572] [subscription_test]: test starting, waiting string...
1: [subscription_test_exe-1] [INFO] [1724167330.305429593] [subscription_test]: Waiting for test topic to be published...
1: [subscription_test_exe-1] [INFO] [1724167330.306510212] [subscription_test]: Test class constructed
1: [test_subscription-2] [       OK ] TestFixture.testPubString (120 ms)
1: [test_subscription-2] [----------] 1 test from TestFixture (120 ms total)
1: [test_subscription-2] 
1: [test_subscription-2] [----------] Global test environment tear-down
1: [test_subscription-2] [==========] 1 test from 1 test suite ran. (120 ms total)
1: [test_subscription-2] [  PASSED  ] 1 test.
```
