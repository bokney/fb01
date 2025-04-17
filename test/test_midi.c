
#include "unity.h"
#include "midi.h"
#include "map.h"


void setUp(void) {}
void tearDown(void) {}

void test_send_without_init(void) {
    int result;
    
    result = send_fb01_param(FB01_ADDR_OP_AR(0), 100, 0);

    TEST_ASSERT_NOT_EQUAL_MESSAGE(
        0, result, 
        "Expected send_fb01_param() to fail when MIDI is not initialized."
    );
}

void test_init(void) {
    int result;
    
    result = fb01_midi_init(0);
    TEST_ASSERT_EQUAL_INT_MESSAGE(
        0, result, "fb01_midi_init() failed when it should succeed."
    );
    
    fb01_midi_close();
}

void test_send_valid(void) {
    int result;
    
    result = fb01_midi_init(0);
    TEST_ASSERT_EQUAL_INT_MESSAGE(
        0, result, "Initialization failed in test_send_valid()."
    );
    
    result = send_fb01_param(FB01_ADDR_OP_AR(0), 100, 0);
    TEST_ASSERT_EQUAL_INT_MESSAGE(
        0, result, "Expected valid parameter update to succeed."
    );
    
    fb01_midi_close();
}


void test_send_after_close(void) {
    int result;
    
    result = fb01_midi_init(0);
    TEST_ASSERT_EQUAL_INT_MESSAGE(
        0, result, "Initialization failed in test_send_after_close()."
    );
    
    fb01_midi_close();
    
    result = send_fb01_param(FB01_ADDR_OP_AR(0), 100, 0);
    TEST_ASSERT_NOT_EQUAL_MESSAGE(
        0, result, "Expected send_fb01_param() to fail after MIDI closure."
    );
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_send_without_init);
    RUN_TEST(test_init);
    RUN_TEST(test_send_valid);
    RUN_TEST(test_send_after_close);
    
    return UNITY_END();
}
