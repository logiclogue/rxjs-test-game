open Mocha;
open Chai;
open Entity;

describe("Entity", () => {
    describe("tick", () => {
        context("velocity = 0", () => {
            let entity = {
                position: (42, 0),
                prevPosition: (0, 0),
                velocity: 0,
                direction: 0.0
            };

            let result = entity->tick;

            it("sets the current position to the previous position", () => {
                expect(result.prevPosition)->t->deep->equal(entity.position);
            });

            it("keeps the position the same", () => {
                expect(result.position)->t->deep->equal(entity.position);
            });
        });

        context("velocity = 1, direction = 0", () => {
            let entity = {
                position: (42, 0),
                prevPosition: (0, 0),
                velocity: 1,
                direction: 0.0
            };

            let result = entity->tick;

            it("sets the position to (43, 0)", () => {
                expect(result.position)->t->deep->equal((43, 0))
            });
        });
    });
});
