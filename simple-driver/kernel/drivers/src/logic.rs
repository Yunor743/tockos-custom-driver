use kernel::{ErrorCode, ProcessId};
use kernel::syscall::{CommandReturn, SyscallDriver};
use kernel::process::Error;

pub const DRIVER_NUM: usize = 0xa0002;

pub struct Logic {}

impl Logic {
  pub fn new() -> Logic {
    Logic {}
  }
}

impl SyscallDriver for Logic {
  fn command(
    &self,
    command_num: usize,
    r2: usize,
    r3: usize,
    _process_id: ProcessId,
  ) -> CommandReturn {
    match command_num {
      0 => { // and
        if r2 == r3 {
          CommandReturn::success_u32(1)
        } else {
          CommandReturn::success_u32(0)
        }
      }
      1 => { // or
        if r2 == 0 && r3 == 0 {
          CommandReturn::success_u32(0)
        } else {
          CommandReturn::success_u32(1)
        }
      }
      _ => CommandReturn::failure(ErrorCode::NOSUPPORT)
    }
  }

  fn allocate_grant(&self, _process_id: ProcessId) -> Result<(), Error> {
    Ok(())
  }
}