# This method is used to execute COMMANDS with an isolated gtest file (unique ROS_DOMAIN_ID).

function(cm_add_isolated_gtest_with_command target)
    # Fetches an unused ROS_DOMAIN_ID
    set(RUNNER "RUNNER" "${ament_cmake_ros_DIR}/run_test_isolated.py")
    # Calls ament_add_test with this domain id and same arguments.
    ament_add_test(
    "${target}"
    RUNNER "${RUNNER}"
    ${ARGN}
  )
endfunction()
