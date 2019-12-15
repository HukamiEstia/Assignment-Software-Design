// tests.cpp
#include "../HPCSimulator/Job.h"
#include <gtest/gtest.h>
 
TEST(JobTest, new_job_short) {
	//Arrange
	//Act
	Job testJob("short");

	//Assert
	ASSERT_GT(testJob.GetComputeTime(), 0);
	ASSERT_GT(testJob.GetnCore(), 0);
	ASSERT_EQ(testJob.GetnGPU(), 0);
	ASSERT_LE(testJob.GetComputeTime(), 3600);
	ASSERT_LE(testJob.GetnCore(), 2*16);
}

TEST(JobTest, new_job_medium) {
	//Arrange
	//Act
	Job testJob("medium");

	//Assert
	ASSERT_GT(testJob.GetComputeTime(), 0);
	ASSERT_GT(testJob.GetnCore(), 0);
	ASSERT_EQ(testJob.GetnGPU(), 0);
	ASSERT_LE(testJob.GetComputeTime(), 8 * 3600);
	ASSERT_LE(testJob.GetnCore(), 12 * 16);
}

TEST(JobTest, new_job_large) {
	//Arrange
	//Act
	Job testJob("large");

	//Assert
	ASSERT_GT(testJob.GetComputeTime(), 0);
	ASSERT_GT(testJob.GetnCore(), 0);
	ASSERT_EQ(testJob.GetnGPU(), 0);
	ASSERT_LE(testJob.GetComputeTime(), 16 * 3600);
	ASSERT_LE(testJob.GetnCore(), 64 * 16);
}

TEST(JobTest, new_job_huge) {
	//Arrange
	//Act
	Job testJob("huge");

	//Assert
	ASSERT_GT(testJob.GetComputeTime(), 0);
	ASSERT_GT(testJob.GetnCore(), 0);
	ASSERT_EQ(testJob.GetnGPU(), 0);
	ASSERT_LE(testJob.GetComputeTime(), 64 * 3600);
	ASSERT_LE(testJob.GetnCore(), 128 * 16);
}


TEST(JobTest, new_job_GPU) {
	//Arrange
	//Act
	Job testJob("gpu");

	//Assert
	ASSERT_GT(testJob.GetComputeTime(), 0);
	ASSERT_GT(testJob.GetnCore(), 0);
	ASSERT_GT(testJob.GetnGPU(), 0);
	ASSERT_LE(testJob.GetComputeTime(), 16 * 3600);
	ASSERT_LE(testJob.GetnCore(), 128 * 16);
	ASSERT_LE(testJob.GetnGPU(), 8);
}

TEST(JobTest, new_job_unknown_type) {
	//Arrange
	//Act
	//Assert
	ASSERT_THROW(Job("unknown type"), std::invalid_argument);
}

TEST(JobTest, get_compute_time) {
	//Arrange
	Job testJob("short");
	
	//Act
	int computeTime = testJob.GetComputeTime();
	
	//Assert
	ASSERT_GT(computeTime, 0);
}

TEST(JobTest, get_number_of_core) {
	//Arrange
	Job testJob("short");
	
	//Act
	int nCore = testJob.GetnCore();
	
	//Assert
	ASSERT_GT(nCore, 0);
}

TEST(JobTest, get_number_of_GPU) {
	//Arrange
	Job testJob("gpu");
	
	//Act
	int nGPU = testJob.GetnGPU();
	
	//Assert
	ASSERT_GT(nGPU, 0);
}

TEST(requestTest, new_request_short) {
	//Arrange
	//Act
	//Assert
}

TEST(requestTest, new_request_medium) {
	//Arrange
	//Act
	//Assert
}

TEST(requestTest, new_request_large) {
	//Arrange
	//Act
	//Assert
}

TEST(requestTest, new_request_huge) {
	//Arrange
	//Act
	//Assert
}

TEST(requestTest, new_request_gpu) {
	//Arrange
	//Act
	//Assert
}

TEST(requestTest, new_request_noRequest) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, new_user_ITsupport) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, new_user_researcher) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, new_user_student) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, generate_job) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, send_request) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, support_generate_request) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, researcher_generate_request) {
	//Arrange
	//Act
	//Assert
}

TEST(UserTest, student_generate_request) {
	//Arrange
	//Act
	//Assert
}
/*
TEST(JobTest, new_job_medium) {
	//Arrange
	//Act
	//Assert
}
TEST(User_GenerateRequest)
TEST(User_GenerateJob_Short)
TEST(User_GenerateJob_Medium)
TEST(User_GenerateJob_Large)
TEST(User_GenerateJob_Huge)
TEST(User_GenerateJob_GPU)
TEST(User_GenerateJob_BadType)
TEST(Core_AssignJob)
TEST(NumberGenerator_Operator)
TEST(Scheduler_AddRequest_Short)
TEST(Scheduler_AddRequest_Medium)
TEST(Scheduler_AddRequest_Large)
TEST(Scheduler_AddRequest_Huge)
TEST(Scheduler_AddRequest_GPU)
TEST(Scheduler_AddRequest_BadType)
TEST(Scheduler_GetJob_Short)
TEST(Scheduler_GetJob_Medium)
TEST(Scheduler_GetJob_Large)
TEST(Scheduler_GetJob_Huge)
TEST(Scheduler_GetJob_GPU)
TEST(Scheduler_GetJob_BadType)
TEST(Scheduler_NextRequest)
TEST(Scheduler_NextRequest_Short)
TEST(Scheduler_NextRequest_Medium)
TEST(Scheduler_NextRequest_Large)
TEST(Scheduler_NextRequest_Huge)
TEST(Scheduler_NextRequest_GPU)
TEST(Scheduler_NextRequest_BadType)
TEST(Scheduler_Pop)
TEST(Scheduler_Pop_Short)
TEST(Scheduler_Pop_Medium)
TEST(Scheduler_Pop_Large)
TEST(Scheduler_Pop_Huge)
TEST(Scheduler_Pop_GPU)
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

