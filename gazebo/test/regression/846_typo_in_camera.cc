/*
 * Copyright (C) 2012-2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include <gazebo/rendering/rendering.hh>
#include "gazebo/test/ServerFixture.hh"

using namespace gazebo;
class Issue846Test : public ServerFixture
{
};


/////////////////////////////////////////////////
// \brief Test for issue #846
TEST_F(Issue846Test, CaptureData)
{
  Load("worlds/empty.world");

  gazebo::rendering::CameraPtr camera(new gazebo::rendering::Camera("",
        this->GetScene(), false));

  EXPECT_FALSE(camera->CaptureData());
  camera->EnableSaveFrame(true);
  EXPECT_TRUE(camera->CaptureData());
  camera->EnableSaveFrame(false);
  EXPECT_FALSE(camera->CaptureData());
}

/////////////////////////////////////////////////
/// Main
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
