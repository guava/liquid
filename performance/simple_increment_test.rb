require 'benchmark'
require_relative '../lib/liquid'

TESTS = 10_000

template_1 = Liquid::Template.parse("Hello: {% increment hello %}")
template_2 = Liquid::Template.parse("Hello: {% cincrement hello %}")

Benchmark.bmbm do |results|
  results.report('increment') { TESTS.times { template_1.render } }
  results.report('cincrement') { TESTS.times { template_2.render } }
end
