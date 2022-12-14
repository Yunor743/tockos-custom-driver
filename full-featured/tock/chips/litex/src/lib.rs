//! Drivers and support modules for LiteX SoCs

#![feature(const_fn_trait_bound)]
#![no_std]
#![crate_name = "litex"]
#![crate_type = "rlib"]

// Exported as the LiteX Register Abstraction may be used by other
// modules
pub mod litex_registers;

pub mod event_manager;
pub mod gpio;
pub mod led_controller;
pub mod liteeth;
pub mod timer;
pub mod uart;
