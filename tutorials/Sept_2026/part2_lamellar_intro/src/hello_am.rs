// Part 2, Section 0: minimal setup/orientation demo — no AMs, no bugs.
// Just prints each PE's my_pe()/num_pes() so you can see the effect of
// --pes and --lamellae before anything else in the tutorial.
use lamellar::active_messaging::prelude::*;

#[AmData(Debug, Copy, Clone)]
struct HelloWorld {
    original_pe: usize, // PE data originated from
}

#[lamellar::am]
impl LamellarAM for HelloWorld {
    async fn exec(self) {
        println!("PE {} was told to say Hello World by PE {} of {}",
                 lamellar::current_pe,
                 self.original_pe,
                 lamellar::num_pes);
    }
} 

#[lamellar::main]
fn main() {
    let world = LamellarWorldBuilder::new().build();
    let my_pe = world.my_pe();
    let _ = world.spawn_am_all(
        HelloWorld {
            original_pe: my_pe,
        }
    ).block();
    world.barrier();
}
