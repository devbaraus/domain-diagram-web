import XCTest
import SwiftTreeSitter
import TreeSitterDddDsl

final class TreeSitterDddDslTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_ddd_dsl())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading DddDsl grammar")
    }
}
