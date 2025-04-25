import { render, screen, fireEvent } from "@testing-library/react";
import { Header } from "./Header";

describe("Header component", () => {
  test("renders title", () => {
    render(<Header />);
    expect(screen.getByText(/poetry website/i)).toBeInTheDocument();
  });

  test("renders search input", () => {
    render(<Header />);
    const input = screen.getByTestId("search-input") as HTMLInputElement;
    expect(input).toBeInTheDocument();

    fireEvent.change(input, { target: { value: "sonnet" } });
    expect(input.value).toBe("sonnet");
  });

  test("renders category dropdown and changes value", () => {
    render(<Header />);
    const select = screen.getByTestId("category-filter") as HTMLSelectElement;
    expect(select).toBeInTheDocument();

    fireEvent.change(select, { target: { value: "love" } });
    expect(select.value).toBe("love");
  });
});
