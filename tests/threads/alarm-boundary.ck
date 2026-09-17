# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(alarm-boundary) begin
(alarm-boundary) slept 1 ticks, requested 1
(alarm-boundary) slept 2 ticks, requested 2
(alarm-boundary) slept 7 ticks, requested 7
(alarm-boundary) PASS
(alarm-boundary) end
EOF
pass;
