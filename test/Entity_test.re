open Mocha;
open Chai;
open Entity;

describe("Entity", () => {
    describe("tick", () => {
        context("velocity = 0", () => {
            let entity = Stubs.still_entity;

            let result = entity->tick;

            it("sets the current position to the previous position", () => {
                expect(result.prevPosition)->t->deep->equal(entity.position);
            });

            it("keeps the position the same", () => {
                expect(result.position)->t->deep->equal(entity.position);
            });
        });

        context("velocity = 1, direction = 0", () => {
            let entity = Stubs.forward_entity;

            let result = entity->tick;

            it("sets the position to (43, 0)", () => {
                expect(result.position)->t->deep->equal((43.0, 0.0))
            });
        });

        context("velocity = 1, direction = PI / 2", () => {
            let entity = Stubs.right_entity;

            let result = entity->tick;

            it("sets the position to (42, 1)", () => {
                expect(result.position)->t->deep->equal((42.0, 1.0))
            });
        });
    });
});
