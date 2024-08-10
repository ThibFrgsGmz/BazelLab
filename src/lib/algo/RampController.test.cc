
#include "RampController.hpp"  

#include <gtest/gtest.h>

/// Test pour vérifier le comportement de la rampe en mode RATE lors de la montée
TEST(RampTest, RateModeRampUp) {
    Ramp ramp(RampMode::RATE, 0.0, 10.0, 2.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 2.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 6.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier le comportement de la rampe en mode RATE lors de la descente
TEST(RampTest, RateModeRampDown) {
    Ramp ramp(RampMode::RATE, 10.0, 0.0, 2.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 8.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 4.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 0.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier le comportement de la rampe en mode DURATION lors de la montée
TEST(RampTest, DurationModeRampUp) {
    Ramp ramp(RampMode::DURATION, 0.0, 10.0, 5.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 2.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 6.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier le comportement de la rampe en mode DURATION lors de la descente
TEST(RampTest, DurationModeRampDown) {
    Ramp ramp(RampMode::DURATION, 10.0, 0.0, 5.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 8.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 4.0);
    EXPECT_DOUBLE_EQ(ramp.update(2.0), 0.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier la réinitialisation de la rampe en mode RATE
TEST(RampTest, ResetRateMode) {
    Ramp ramp(RampMode::RATE, 0.0, 10.0, 2.0);
    ramp.update(1.0);
    
    ramp.reset(RampMode::RATE, 5.0, 15.0, 2.5);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 7.5);
    EXPECT_DOUBLE_EQ(ramp.update(3.0), 15.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier la réinitialisation de la rampe en mode DURATION
TEST(RampTest, ResetDurationMode) {
    Ramp ramp(RampMode::DURATION, 0.0, 10.0, 5.0);
    ramp.update(1.0);
    
    ramp.reset(RampMode::DURATION, 5.0, 15.0, 4.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(1.0), 7.5);
    EXPECT_DOUBLE_EQ(ramp.update(3.0), 15.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier que la rampe atteint correctement la valeur cible
TEST(RampTest, TargetValueReachedRateMode) {
    Ramp ramp(RampMode::RATE, 0.0, 10.0, 3.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(5.0), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier que la rampe atteint correctement la valeur cible en mode DURATION
TEST(RampTest, TargetValueReachedDurationMode) {
    Ramp ramp(RampMode::DURATION, 0.0, 10.0, 5.0);
    
    EXPECT_DOUBLE_EQ(ramp.update(5.0), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier que la rampe ne dépasse pas la valeur cible en mode RATE
TEST(RampTest, NoOvershootRateMode) {
    Ramp ramp(RampMode::RATE, 0.0, 10.0, 3.0);
    
    ramp.update(3.5);
    EXPECT_DOUBLE_EQ(ramp.get_current_value(), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}

/// Test pour vérifier que la rampe ne dépasse pas la valeur cible en mode DURATION
TEST(RampTest, NoOvershootDurationMode) {
    Ramp ramp(RampMode::DURATION, 0.0, 10.0, 5.0);
    
    ramp.update(5.5);
    EXPECT_DOUBLE_EQ(ramp.get_current_value(), 10.0);
    EXPECT_TRUE(ramp.is_finished());
}
