use kernel::{ErrorCode, ProcessId};
use kernel::syscall::{CommandReturn, SyscallDriver};
use kernel::process::Error;

pub const DRIVER_NUM: usize = 0xa0001;

pub struct Arithmetic {}

impl Arithmetic {
  pub fn new() -> Arithmetic {
    Arithmetic {}
  }
}

impl SyscallDriver for Arithmetic {
  fn command(
    &self,
    command_num: usize,
    r2: usize,
    r3: usize,
    _process_id: ProcessId,
  ) -> CommandReturn {
    match command_num {
      0 => CommandReturn::success_u32((r2 + r3) as u32), // add
      1 => CommandReturn::success_u32((r2 - r3) as u32), // sub
      2 => CommandReturn::success_u32((r2 * r3) as u32), // mul
      3 => CommandReturn::success_u32((r2 / r3) as u32), // div
      4 => CommandReturn::success_u32((r2 % r3) as u32), // mod
      _ => CommandReturn::failure(ErrorCode::NOSUPPORT)
    }
  }

  fn allocate_grant(&self, _process_id: ProcessId) -> Result<(), Error> {
    Ok(())
  }
}