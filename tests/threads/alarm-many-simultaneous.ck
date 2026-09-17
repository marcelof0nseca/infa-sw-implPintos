# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(alarm-many-simultaneous) begin
(alarm-many-simultaneous) Creating 20 threads to sleep until the same tick.
(alarm-many-simultaneous) All 20 threads woke up at the same tick, as expected.
(alarm-many-simultaneous) PASS
(alarm-many-simultaneous) end
EOF
pass;
