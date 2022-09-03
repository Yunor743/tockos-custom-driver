use kernel::{ErrorCode, ProcessId, debug};
use kernel::hil::gpio::Configuration::Output;
use kernel::syscall::{CommandReturn, SyscallDriver};
use kernel::process::Error;
use kernel::hil::time::{Alarm, AlarmClient, ConvertTicks};
use kernel::hil::gpio::Pin;

pub const DRIVER_NUM: usize = 0xa0004;

pub struct Locker<'a, A: Alarm<'a>> {
  alarm: &'a A,
  pin1: &'a dyn Pin,
  pin2: &'a dyn Pin,
  pin3: &'a dyn Pin,
  pin4: &'a dyn Pin,
  pin5: &'a dyn Pin,
  pin6: &'a dyn Pin,
  pin7: &'a dyn Pin,
  expectedDigitNb: u8,
  expectedVal: u32,
}

impl<'a, A: Alarm<'a>> Locker<'a, A> {
  pub fn new(
    alarm: &'a A,
    pin1: &'a Pin,
    pin2: &'a Pin,
    pin3: &'a Pin,
    pin4: &'a Pin,
    pin5: &'a Pin,
    pin6: &'a Pin,
    pin7: &'a Pin,
    secret: u16,
  ) -> Locker<'a, A> {
    pin1.make_output();
    pin2.make_output();
    pin3.make_output();
    pin4.make_output();
    pin5.make_output();
    pin6.make_output();
    pin7.make_output();
    let mut digitNb: u8 = 0;
    let mut value: u32 = 0;

    // count digits and value:
    // TODO deduce automatically "expectedDigitNb" and "exepectedVal" from "secret"
    digitNb = 4; // temp fix : if secret is "1234"
    value = 10; // temp fix : if secret is "1234" = 1+2+3+4 = 10

    Locker {
      alarm,
      pin1,
      pin2,
      pin3,
      pin4,
      pin5,
      pin6,
      pin7,
      expectedDigitNb: digitNb,
      expectedVal: value,
    }
  }
}

impl<'a, A: Alarm<'a>> SyscallDriver for Locker<'a, A> {
  fn command(
    &self,
    command_num: usize,
    r2: usize,
    r3: usize,
    _process_id: ProcessId,
  ) -> CommandReturn {
    match command_num {
      // OK
      0 => {
        debug!("Locker driver OK");
        CommandReturn::success()
      }
      // START
      1 => {
        self.alarm.set_alarm(self.alarm.now(), self.alarm.ticks_from_ms(10));
        debug!("Locker service started");
        CommandReturn::success()
      }
      // STOP
      2 => {
        match  self.alarm.disarm() {
          Ok(_) => {
            debug!("Locker service stopped");
            CommandReturn::success()
          }
          Err(error) => CommandReturn::failure(error)
        }
      }
      _ => CommandReturn::failure(ErrorCode::NOSUPPORT)
    }
  }

  fn allocate_grant(&self, _process_id: ProcessId) -> Result<(), Error> {
    Ok(())
  }
}

impl<'a, A: Alarm<'a>> AlarmClient for Locker<'a, A> {
  fn alarm(&self) {
    let mut digitNb: u8 = 0;
    let mut curVal: u32 = 0;

    // Read pins
    if self.pin1.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 1;
    }
    if self.pin2.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 2;
    }
    if self.pin3.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 3;
    }
    if self.pin4.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 4;
    }
    if self.pin5.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 5;
    }
    if self.pin6.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 6;
    }
    if self.pin7.read() {
      digitNb = digitNb + 1;
      curVal = curVal + 7;
    }

    // compare values, current with expected
    if digitNb < self.expectedDigitNb {
    } else if digitNb == self.expectedDigitNb && curVal == self.expectedVal {
      debug!("SUCCESS");
      // TODO blink a led and reset the locker
    } else {
      debug!("digitNb : {} expectedDigitNb : {}", digitNb, self.expectedDigitNb);
      debug!("curVal : {} expectedVal : {}", curVal, self.expectedVal);
      if self.pin1.read() {self.pin1.toggle();}
      if self.pin2.read() {self.pin2.toggle();}
      if self.pin3.read() {self.pin3.toggle();}
      if self.pin4.read() {self.pin4.toggle();}
      if self.pin5.read() {self.pin5.toggle();}
      if self.pin6.read() {self.pin6.toggle();}
      if self.pin7.read() {self.pin7.toggle();}
    }
    // restart the alarm
    self.alarm.set_alarm(self.alarm.now(), self.alarm.ticks_from_ms(10));
  }
}