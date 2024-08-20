#! /usr/bin/env python3

import os
import sys

from ament_index_python import get_package_share_directory
from launch import LaunchDescription, LaunchService
from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from launch_testing.legacy import LaunchTestService


def generate_launch_description():

    return LaunchDescription(
        [
            Node(
                package="iw_poi_registry",
                name="subscription_test",
                executable="subscription_test_exe",
                output="screen",
            )
        ]
    )


def main(argv=sys.argv[1:]):  # pylint: disable=W0102
    ld = generate_launch_description()
    testExecutable = os.getenv("TEST_EXECUTABLE")
    test1_action = ExecuteProcess(cmd=[testExecutable], name="test_subscription", output="screen")
    lts = LaunchTestService()
    lts.add_test_action(ld, test1_action)
    ls = LaunchService(argv=argv)
    ls.include_launch_description(ld)
    return lts.run(ls)


if __name__ == "__main__":
    sys.exit(main())
