use kernel::{ErrorCode, ProcessId, debug};
use kernel::syscall::{CommandReturn, SyscallDriver};
use kernel::process::Error;

pub const DRIVER_NUM: usize = 0xa0000;

pub struct Hello {}

impl Hello {
  pub fn new() -> Hello {
    Hello {}
  }
}

impl SyscallDriver for Hello {
  fn command(
    &self,
    command_num: usize,
    _r2: usize,
    _r3: usize,
    _process_id: ProcessId,
  ) -> CommandReturn {
    match command_num {
      0 => CommandReturn::success(),
      1 => {
        debug!("Hello from driver !");
        CommandReturn::success()
      }
      _ => CommandReturn::failure(ErrorCode::NOSUPPORT)
    }
  }

  fn allocate_grant(&self, _process_id: ProcessId) -> Result<(), Error> {
    Ok(())
  }
}